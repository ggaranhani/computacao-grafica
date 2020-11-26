//#include <windows.h>
#include <GL/glut.h>
#include <stdio.h>
#include <math.h>

int raio = 100,
    count = 0,
    xA = 250,
    xB = 0,
    yA = 250,
    yB = 0,
    pinta = 0;


void pinta_pixel(int x, int y){
  glBegin(GL_POINTS);
      glVertex2i(xA+x, yA+y);
      glVertex2i(xA+x, yA-y);
      glVertex2i(xA+y, yA+x);
      glVertex2i(xA+y, yA-x);
      glVertex2i(xA-x, yA-y);
      glVertex2i(xA-y, yA-x);
      glVertex2i(xA-x, yA+y);
      glVertex2i(xA-y, yA+x);
  glEnd();
}

void circuloBresenham(){
    int x = 0;
    int y = raio;
    float d = 3-2*raio;

    while(x < y){
        x = x + 1;
        if(d < 0)
            d = d + 2*x + 1;
        else{
            y = y - 1;
            d = d + 2*(x - y) + 1;
        }
        pinta_pixel(x,y);
    }
    pinta++;
    printf("pinta_pixel: %d\n", pinta);
    //glFlush();
}

void Init(){
  glClear(GL_COLOR_BUFFER_BIT);
  glClearColor(0,0,0,1);
  gluOrtho2D(0 , 500, 0, 500);
}

void mouseInt(int botao, int estado, int x, int y){
    printf("count: %d\n", count);
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
                raio = sqrt((xB-xA)*(xB-xA)+(yB-yA)*(yB-yA));
                circuloBresenham();
             }
             count++;
          }
          break;
    }
    if(count%2==0){
        glutPostRedisplay();
    }
    //glutPostRedisplay();
}

void display(){
    glutMouseFunc(mouseInt);
    glFlush();
}

int main(int argc, char **argv){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(500,500);
    glutCreateWindow("CIRCULO BRESENHAM");
    Init();
    glutDisplayFunc(display);
    //glutDisplayFunc(circuloBresenham);
    //glutMouseFunc(mouseInt);
    glutMainLoop();
    return 0;
}
