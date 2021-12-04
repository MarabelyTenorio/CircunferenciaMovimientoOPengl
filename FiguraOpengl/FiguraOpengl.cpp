// CIRCUNFERENCIAopengl.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include<glut.h>
#include<math.h>

const float PI = 3.1416;

float formula = 2 * PI / 100;
float radio = 0.2;


GLfloat xi = 0.0;
GLfloat yi = 0.0;

void timer(int)
{
	glutTimerFunc(20, timer, 0);
}

void VERTICES() {
	//GRAFICANDO LOS EJES X y Y
	glBegin(GL_LINES);
	glColor3f(1.0, 0.0, 0.0);
	//Y
	glVertex3f(0.0, 1.0, 0.0);
	glVertex3f(0.0, -1.0, 0.0);
	//X
	glVertex3f(1.0, 0.0, 0.0);
	glVertex3f(-1.0, 0.0, 0.0);
	glEnd();
}

void semicircunferenciasize() {
	//circunferencia completa con determinado tamano
	glBegin(GL_LINE_LOOP); //0.28, 0.50
	glColor3f(0.0, 0.0, 0.0);//baby Blue

	for (float i = 0.0; i < 100; i++) {
		float x = (float)sin(i * formula) * radio;
		float y = yi - (float)cos(i * formula) * radio;
		glVertex2f(x, y);
	}
	glEnd();
}


void ArrowKey(int key, int x, int y) {
	glutPostRedisplay();
	switch (key) {
	case GLUT_KEY_RIGHT:
		xi += 0.04;
		break;
	case GLUT_KEY_LEFT:
		xi -= 0.04;
		break;
	case GLUT_KEY_UP:
		yi += 0.04;
		break;
	case GLUT_KEY_DOWN:
		yi -= 0.04;
		break;
	}
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key) {
	case 32:
		semicircunferenciasize();
		break;
	case 27:
		exit(0);
		break;
	}
}

void grafico() {
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glPointSize(5); //definiendo ancho del pixel
	glLineWidth(4);

	glLoadIdentity();
	glPushMatrix();

	VERTICES();
	glTranslatef(xi, yi, 0.0);
	glRotatef(10, 0, 0, 1);
	semicircunferenciasize();
	glPopMatrix();

	glFlush();
}



int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE | GLUT_DEPTH);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Laboratorio1 PG");
	glutDisplayFunc(grafico);

	glutIdleFunc(grafico);
	glutSpecialFunc(ArrowKey);

	glutMainLoop();
	return 0;

}
