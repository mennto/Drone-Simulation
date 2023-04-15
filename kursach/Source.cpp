#include <GLFW/glfw3.h>
#include <ctime>
#include <cstdlib>
#include <chrono>
#include <thread>
#include "Carrier.h"
#include "Commander.h"
#include "Communicator.h"
#include "Func.h"

using namespace std;

bool infoDrawed;
Carrier carrier1,carrier2;
Commander commander;
Communicator communicator;
Drone* drone[CNT]={ &carrier1,&carrier2,&commander,&communicator };
Point mas[4];

void DrawSquare(float x, float y, float red, float green, float blue) {
    glBegin(GL_TRIANGLE_STRIP);
    glColor3f(red, green, blue);
    glVertex2f(x + FAULT, y + FAULT);
    glVertex2f(x + SELL_SIZE - FAULT, y + FAULT);
    glVertex2f(x + FAULT, y + SELL_SIZE - FAULT);
    glVertex2f(x + SELL_SIZE - FAULT, y + SELL_SIZE - FAULT);
    glEnd();
}

bool checkRepeat(int x,int y,int range) {
    for (int i = 0; i < range; i++)
        if (drone[i]->getCurrentX() == x||drone[i]->getDestinationX()==y)
            return true;
        return false;
}

void identifyMas() {
    for (int i = 0; i < CNT; i++) {
        mas[i].setX(drone[i]->getCurrentX());
        mas[i].setY(drone[i]->getCurrentY());
    }
}

void identifyDrones() {
    int xFinish, xStart;
    for (int i = 0; i < CNT; i++) {
        xStart = randCordinate(ROW);
        xFinish = commander.giveDestinationForDrone(ROW);
        if (i != 0 && checkRepeat(xStart, xFinish, i))
            i--;
        else {
              drone[i]->enterInfo();
            drone[i]->setCurrentX(xStart);
            drone[i]->setCurrentY(yStart);
            drone[i]->setDestinationX(xFinish);
            drone[i]->setDestinationY(COL);
            drone[i]->setBattery(ROW + COL);
            drone[i]->setFinished(false);
            drone[i]->setStarted(false);
        }
    }  
}

void ShowDrones() {
    for (int i = 0; i < CNT; i++) {   
        if (!drone[i]->getStarted()) {
            drone[i]->setStarted(true);
            DrawSquare(drone[i]->getCurrentX(), drone[i]->getCurrentY(), 0, i * 0.3, 0);
            this_thread::sleep_for(chrono::microseconds(200000));
        }
        else {
            for (int j = 0; j < drone[i]->getVelocity(); j++) {
                identifyMas();
                if (drone[i]->getCurrentX() == drone[i]->getDestinationX()
                    && drone[i]->getCurrentY() == drone[i]->getDestinationY()
                    && drone[i]->getFinished() == false) {
                    drone[i]->arrived();
                    drone[i]->setFinished(true);
                }
                    drone[i]->move(mas);
                   
           }
            DrawSquare(drone[i]->getCurrentX(), drone[i]->getCurrentY(), 0, i * 0.3, 0);
            this_thread::sleep_for(chrono::microseconds(200000));
        }
    }
}

bool AllDronesArrived() {
    for (int i = 0; i < CNT; i++)
        if (!drone[i]->getFinished())
            return false;
    return true;
}

void StartGame() {
    glLoadIdentity();
    glScalef(1/(KOF* ROW), 1/(KOF* COL), 1);
    glTranslatef(-ROW * KOF-1, -COL * KOF-1, 0);
    for (int x=1; x <= ROW; x++) 
        for (int y = 1; y <= COL; y++) {
            DrawSquare(x, y,0.455,0.455,0.404);
        }
}

void showInfo() {
    system("cls");
    for (int i = 0; i < CNT; i++)
        drone[i]->info();
}

int main(void){
    srand(time(NULL));
    GLFWwindow* window;

    if (!glfwInit())
        return -1;

    window = glfwCreateWindow(700, 700, "Drone Simulation", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    identifyDrones();

    while (!glfwWindowShouldClose(window)) {
        glClearColor(0.0f, 0.204f, 0.255f, 0.0f);
        glClear(GL_COLOR_BUFFER_BIT);
       
        StartGame();
        if (!AllDronesArrived())
            ShowDrones();
        else if (!infoDrawed) {
            showInfo();
            infoDrawed = true;
        }
        for (int i = 0; i < CNT; i++) {
          DrawSquare(drone[i]->getDestinationX(), drone[i]->getDestinationY(), 0, i * 0.3, 0);
        }

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwTerminate();
    return 0;
}