/*
 * GameProcess.cpp
 *
 *  Created on: 4 июля 2016 г.
 *      Author: CHESTER
 */

#include "GameProcess.h"

struct SVertex {
	GLfloat x, y, z;
	GLfloat r, g, b;
};

SVertex a[3] = { SVertex { -1, 0, 0, 1, 0, 0 }, SVertex { 0, 5, 0, 1, 0, 0 },
		SVertex { 1, 0, 0, 1, 0, 0 } };

GLfloat vertA[3] = { 0.5, 1, 0.5 };
GLfloat vertB[3] = { -0.5, 1, 0.5 };
GLfloat vertC[3] = { -0.5, 0, 0.5 };
GLfloat vertD[3] = { 0.5, 0, 0.5 };
GLfloat vertE[3] = { 0.5, 1, -0.5 };
GLfloat vertF[3] = { -0.5, 1, -0.5 };
GLfloat vertG[3] = { -0.5, 0, -0.5 };
GLfloat vertH[3] = { 0.5, 0, -0.5 };

GLuint *ind;

int N = 30, M = 20;
int Scale = 25;
int w = Scale * N;
int h = Scale * M;
int dir, num = 4;
int pastX, pastY;
Camera* camera;
GameProcess::GameProcess(int argc, char **argv) {
	ind = new GLuint[3];
	ind[0] = 0;
	ind[1] = 1;
	ind[2] = 2;
	srand(time(NULL));
	Init(argc, argv);

}

GameProcess::~GameProcess() {
	// TODO Auto-generated destructor stub
}

void DrawGrid() {
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			glLoadIdentity();
			glTranslatef((float) i, -1.0f, -(float) j); // Move right and into the screen

			glBegin(GL_QUADS);      // Begin drawing the color cube with 6 quads
			float r = rand() % 100 / 100.0f;
			float g = rand() % 100 / 100.0f;
			float b = rand() % 100 / 100.0f;

			glColor3f(0, 1, 0);
			glVertex3f(-0.5f, 0.0f, -0.5f);
			glVertex3f(0.5f, 0.0f, -0.5f);
			glVertex3f(0.5f, 0.0f, 0.5f);
			glVertex3f(-0.5f, 0.0f, 0.5f);

			glEnd();
		}

	}

}
void changeCamera() {
	vector3 newPos = camera->getPosition();
	newPos.x += 0.013f;
	camera->setPosition(newPos);

	//glMatrixMode(GL_PROJECTION);
	//glLoadIdentity();
	//gluLookAt(camera->getPosition().x,camera->getPosition().y,camera->getPosition().z,0,0,0,0,1,0);
}

void drawCube() {
	glBegin(GL_QUADS);

	glVertex3fv(vertA);
	glVertex3fv(vertB);
	glVertex3fv(vertC);
	glVertex3fv(vertD);

	glVertex3fv(vertF);
	glVertex3fv(vertE);
	glVertex3fv(vertH);
	glVertex3fv(vertG);

	glVertex3fv(vertE);
	glVertex3fv(vertA);
	glVertex3fv(vertD);
	glVertex3fv(vertH);

	glVertex3fv(vertB);
	glVertex3fv(vertF);
	glVertex3fv(vertG);
	glVertex3fv(vertC);

	glVertex3fv(vertE);
	glVertex3fv(vertF);
	glVertex3fv(vertB);
	glVertex3fv(vertA);

	glVertex3fv(vertD);
	glVertex3fv(vertC);
	glVertex3fv(vertG);
	glVertex3fv(vertH);

	glEnd();
}
vector3 takeVectorTranslate(){
	vector3 offset;
	offset.x=snake[0].x-camera->getPosition().x;
	offset.y=7;
	offset.z=15;

	return offset;
}
void GameProcess::Draw(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(255, 255, 255, 1.0);
	camera->setPosition(vector3 { 10, 30, 21 });
	glLoadIdentity();
	glMatrixMode(GL_PROJECTION);
	//glLoadIdentity();

	glTranslatef(0, 0, 0);
	/*gluLookAt(camera->getPosition().x,
	 camera->getPosition().y,
	 camera->getPosition().z,
	 (float) N / 2.0, 0, -(float) M / 2.0, 0, 1, 0);
	 */
	glMatrixMode(GL_MODELVIEW);

	DrawGrid();
	for (int i = 0; i < num; ++i) {
		glLoadIdentity();
		glTranslatef((float) snake[i].x, -1.0f, -(float) snake[i].y);
		if (i == 0)
			glColor3f(1, 0, 0);
		else {
			if (i % 2 == 0) {
				glColor3f(1, 1, 1);
			} else {
				glColor3f(0, 0, 0);
			}
		}

		drawCube();

		//Draw Eat
		glColor3f(0, 0, 1);
		glLoadIdentity();
		glTranslatef((float) eat.x, -1.0f, -(float) eat.y);
		drawCube();

	}
	/*
	 //DRAWING
	 glVertexPointer(3, GL_FLOAT, sizeof(SVertex), a);
	 glColorPointer(3, GL_FLOAT, sizeof(SVertex), &a[0].r);
	 glDrawElements( GL_TRIANGLES, //mode
	 3,  //count, ie. how many indices
	 GL_UNSIGNED_INT, //type of the index array
	 ind);
	 ///
	 ///DRAWING
	 */

	/*
	 for (int i = 0; i < num; ++i) {
	 if (i == 0)
	 glColor3f(0, 0, 1);
	 else
	 glColor3f(0, 1, 0);
	 glRectf(snake[i].x * Scale, snake[i].y * Scale,
	 (snake[i].x + 1) * Scale, (snake[i].y + 1) * Scale);
	 }

	 glColor3f(1, 0, 0);
	 glRectf(eat.x * Scale, eat.y * Scale, (eat.x + 1) * Scale,
	 (eat.y + 1) * Scale);
	 */

	glutSwapBuffers();

}

int intersectSnakeWithHimSelf() {
	int x = snake[0].x;
	int y = snake[0].y;
	for (int i = 1; i < num; ++i) {
		if (x == snake[i].x && y == snake[i].y) {
			return i;
		}
	}
	return -1;
}

void restartSnake() {

	if (intersectSnakeWithHimSelf() != -1) {

		num = intersectSnakeWithHimSelf();

	}
}

void GameProcess::Update() {

	//cout << "Timer" << endl;
	restartSnake();
	pastX = snake[num - 1].x;
	pastY = snake[num - 1].y;
	for (int i = num; i > 0; --i) {
		snake[i].x = snake[i - 1].x;
		snake[i].y = snake[i - 1].y;
	}
	if (dir == 0)
		snake[0].y += 1;
	if (dir == 1)
		snake[0].x += 1;
	if (dir == 2)
		snake[0].y -= 1;
	if (dir == 3)
		snake[0].x -= 1;

	if (snake[0].x > N - 1)
		snake[0].x = 0;
	if (snake[0].x < 0)
		snake[0].x = N - 1;
	if (snake[0].y > M - 1)
		snake[0].y = 0;
	if (snake[0].y < 0)
		snake[0].y = M - 1;

	checkIntersects();
	changeCamera();
	cout << "Camera x: " << camera->getPosition().x << " "
			<< camera->getPosition().y << " " << camera->getPosition().z
			<< endl;
	//cout << "EAT " << eat.x << " " << eat.y << endl;

}

void GameProcess::Init(int argc, char **argv) {

	snake[0].x = 6;
	snake[0].y = 6;
	snake[1].x = 6;
	snake[1].y = 5;
	snake[2].x = 6;
	snake[2].y = 4;
	snake[3].x = 6;
	snake[3].y = 3;
	placeEat();
	camera = new Camera((float) N / 2.0, 15, 22);
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(w, h);
	glutInitWindowPosition(100, 100);

	glutCreateWindow("Game_Snake");

	cout << "Sozdano" << endl;
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f, (float) w / (float) h, 0.1, 1000);
	vector3 campos = camera->getPosition();
	gluLookAt(campos.x, campos.y, campos.z, (float) N / 2.0, 0,
			-(float) M / 2.0, 0, 1, 0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glEnable(GL_DEPTH_TEST);
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);

	glutDisplayFunc(Draw);
	glutTimerFunc(60, Timer, 0);
	glutTimerFunc(60, TimerUpdate, 0);

	glutKeyboardFunc(KeyboardWrapper);
	glutKeyboardUpFunc(KeyboardUpWrapper);
	glutMainLoop();
}

void GameProcess::KeyboardWrapper(unsigned char key, int x, int y) {
	cout << "Press " << key << endl;
	if (key == 'w')
		dir = 0;
	if (key == 'd')
		dir = 1;
	if (key == 's')
		dir = 2;
	if (key == 'a')
		dir = 3;
}

void GameProcess::KeyboardUpWrapper(unsigned char key, int x, int y) {
	cout << "Up " << key << endl;

}

void GameProcess::Timer(int t) {

	Draw();

	glutTimerFunc(1000 / 60, Timer, 0);
}

bool isIntersected(int x, int y) {
	for (int i = 0; i < num; ++i) {
		if (x == snake[i].x && y == snake[i].y) {
			return true;
		}
	}
	return false;
}

void GameProcess::TimerUpdate(int t) {
	Update();
	glutTimerFunc(80, TimerUpdate, 0);
}

void GameProcess::placeEat() {
	bool isPlace = false;
	while (!isPlace) {
		int x = rand() % N;
		int y = rand() % M;
		if (!isIntersected(x, y)) {
			eat.x = x;
			eat.y = y;
			isPlace = true;
		}
	}

}
void GameProcess::checkIntersects() {
	if (snake[0].x == eat.x && snake[0].y == eat.y) {
		snake[num].x = pastX;
		snake[num].y = pastY;
		num++;
		placeEat();
	}
}

