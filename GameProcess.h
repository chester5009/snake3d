/*
 * GameProcess.h
 *
 *  Created on: 4 июля 2016 г.
 *      Author: CHESTER
 */
#include <iostream>
#include <GL/freeglut.h>
#include <GL/glu.h>
#include <time.h>
#include "Camera.h"
using namespace std;

#ifndef GAMEPROCESS_H_
#define GAMEPROCESS_H_



struct {
	int x;
	int y;
}snake[100];


struct{
	int x;
	int y;
} eat;
class GameProcess {
public:
	GameProcess(int argc, char **argv);
	virtual ~GameProcess();


private:
	void Init(int, char **);
	static void Update();
	static void Draw();
	static void KeyboardWrapper(unsigned char key,int x,int y);
	static void KeyboardUpWrapper(unsigned char key,int x,int y);
	static void Timer(int);
	static void TimerUpdate(int);
	static void Reshape(int w,int h);
	static void checkIntersects();
	static void placeEat();

	bool isRun;
};

#endif /* GAMEPROCESS_H_ */
