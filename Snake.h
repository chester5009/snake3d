/*
 * Snake.h
 *
 *  Created on: 4 июля 2016 г.
 *      Author: CHESTER
 */

#include <vector>
using namespace std;

#ifndef SNAKE_H_
#define SNAKE_H_

struct Part{
	int x;
	int y;
};

class Snake {
private:
	vector<Part>snake;
	int dir;//0-up 1-right 2-bottom 3-left
	Part forNewPart;
public:
	Snake();
	virtual ~Snake();
	void update();

};

#endif /* SNAKE_H_ */
