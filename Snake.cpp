/*
 * Snake.cpp
 *
 *  Created on: 4 èşëÿ 2016 ã.
 *      Author: CHESTER
 */

#include "Snake.h"

Snake::Snake() {

	snake.push_back(Part{5,5});
	snake.push_back(Part{5,4});

}

Snake::~Snake() {
	// TODO Auto-generated destructor stub
}

void Snake::update() {

	for (int i = snake.size() - 1; i > 0; i--) {

	}

	for (int i = snake.size() - 1; i > 0; i--) {
		snake[i].x = snake[i - 1].x;
		snake[i].y = snake[i - 1].y;
	}
	switch (dir) {
	case 0:
		snake[0].y--;
		break;
	case 1:
		snake[0].x++;
		break;
	case 2:
		snake[0].y++;
		break;
	case 3:
		snake[0].x--;
		break;
	}
}
