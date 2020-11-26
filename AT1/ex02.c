#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

float x_desenho = 0.0;
float y_desenho = 0.0;

void init(){
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glPointSize(5);
    glColor3f(0.0,0.0,1.0);
}

void desenho(){
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS);
        glVertex2f(x_desenho,y_desenho);
    glEnd();
    glFlush();
}

void MouseInt (int botao, int estado, int x, int y){
    switch(botao){
       case GLUT_LEFT_BUTTON:
          if(estado == GLUT_DOWN){
             x_desenho = ((float)x/300)-1;
             y_desenho = -(((float)y/300)-1);
             printf("\n\nx = %d, x_desenho = %f",x,x_desenho);
             printf("\ny = %d, y_desenho = %f",y,y_desenho);
          }
          break;
    }
    glutPostRedisplay();
}

void Keyboard (unsigned char key, int x, int y){
    switch(key){
       case '0':
          glColor3f(1.0,1.0,1.0);
          break;
       case '1':
          glColor3f(0.5,0.0,0.0);
          break;
       case '2':
          glColor3f(1.0,0.0,0.0);
          break;
       case '3':
          glColor3f(0.0,0.5,0.0);
          break;
       case '4':
          glColor3f(0.0,1.0,0.0);
          break;
       case '5':
          glColor3f(0.0,0.0,0.5);
          break;
       case '6':
          glColor3f(0.0,0.0,1.0);
          break;
       case '7':
          glColor3f(1.0,0.5,0.0);
          break;
       case '8':
          glColor3f(1.0,1.0,0.0);
          break;
       case '9':
          glColor3f(1.0,0.5,1.0);
          break;
    }
    glutPostRedisplay();
}

int main( int argc, char *argv[ ] ){
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(50,100);
    glutInitWindowSize(600,600);
    glutInit(&argc, argv);
    glutCreateWindow("Cria um triângulo");
    init();
    glutDisplayFunc(desenho);
    glutMouseFunc(MouseInt);
    glutKeyboardFunc(Keyboard);
    glutMainLoop ();
    return 0;
}
