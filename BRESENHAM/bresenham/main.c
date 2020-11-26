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


void retaBresenham(){
	int dx, dy, i, e;
	int mx = 1, my = 1, m1, m2;
	int x,y;

	dx = xB - xA;
	dy = yB - yA;

	if (dx < 0)
        dx = -dx;
	if (dy < 0)
        dy = -dy;

	if (xB < xA)
        mx = -1;

	if (yB < yA)
        my = -1;

	x = xA;
	y = yA;

	if (dx > dy) {
		pinta_pixel(x, y);
		e = 2 * (dy-dx);
		m1 = 2*(dy-dx);
		m2 = 2*dy;
		for (i = 0; i < dx; i++) {
			if (e >= 0) {
				y += my;
				e += m1;
			}
			else{
				e += m2;
			}
			x += mx;
			pinta_pixel(x, y);
		}

	}else{
		pinta_pixel(x, y);
		e = 2*(dx-dy);
		m1 = 2*(dx-dy);
		m2 = 2*dx;
		for (i = 0; i < dy; i++) {
			if (e >= 0) {
				x += mx;
				e += m1;
			}
			else{
				e += m2;
			}
			y += my;
			pinta_pixel(x, y);
		}
	}
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
	glutCreateWindow("RETA BRESENHAM");
	init();
	glutDisplayFunc(retaBresenham);
	glutMouseFunc(mouseInt);
	glutMainLoop();
	count++;
    return 0;
}
