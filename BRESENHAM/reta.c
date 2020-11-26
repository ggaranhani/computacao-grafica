//#include <windows.h>
#include <GL/glut.h>

#include <stdio.h>
#include <time.h>

int xA, yA, xB, yB;
int count = 0;

void init() {
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, 500, 0, 500);
}

void pinta_pixel(int x, int y) {
	glBegin(GL_POINTS);
        glVertex2i(x, y);
	glEnd();
}


void draw_line(){
	int dx, dy, i, e;
	int incx = 1, incy = 1, inc1, inc2;
	int x,y;

	dx = xB - xA;
	dy = yB - yA;

	if (dx < 0)
        dx = -dx;
	if (dy < 0)
        dy = -dy;

	if (xB < xA)
        incx = -1;

	if (yB < yA)
        incy = -1;

	x = xA;
	y = yA;

	if (dx > dy) {
		pinta_pixel(x, y);
		e = 2 * (dy-dx);
		inc1 = 2*(dy-dx);
		inc2 = 2*dy;
		for (i = 0; i < dx; i++) {
			if (e >= 0) {
				y += incy;
				e += inc1;
			}
			else{
				e += inc2;
			}
			x += incx;
			pinta_pixel(x, y);
		}

	}else{
		pinta_pixel(x, y);
		e = 2*(dx-dy);
		inc1 = 2*(dx-dy);
		inc2 = 2*dx;
		for (i = 0; i < dy; i++) {
			if (e >= 0) {
				x += incx;
				e += inc1;
			}
			else{
				e += inc2;
			}
			y += incy;
			pinta_pixel(x, y);
		}
	}
}

void myDisplay() {
	draw_line(xA, xB, yA, yB);
	glFlush();
}

void mouseInt(int botao, int estado, int x, int y){
    switch(botao){
       case GLUT_LEFT_BUTTON:
          if(estado == GLUT_DOWN){
             if(count%2 == 0){
                xA = x;
                yA = 500-y;
             }
             else{
                xB = x;
                yB = 500-y;
             }
             count++;
          }
          break;
    }
    if(count%2==0){
        glutPostRedisplay();
    }
    glutPostRedisplay();
}

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Bresenham's Line Drawing");
	init();
	glutDisplayFunc(myDisplay);
	glutMouseFunc(mouseInt);
	glutMainLoop();
	count++;
    return 0;
}
