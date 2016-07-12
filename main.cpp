#include <iostream>
#include <GL/freeglut.h>
#include "GameProcess.h"
using namespace std;

int main(int argc, char **argv) {

	GameProcess* game=new GameProcess(argc,argv);

	return 0;
}

