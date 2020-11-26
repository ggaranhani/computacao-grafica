#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

float x01_desenho = 0.0;
float y01_desenho = 0.0;
float x02_desenho = 0.0;
float y02_desenho = 0.0;
int cont = 0;

void init(){
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glLineWidth (5);
    glColor3f(1.0,1.0,1.0);
}

void desenho(){
    glBegin(GL_LINES);
        glVertex2f(x01_desenho,y01_desenho);
        glVertex2f(x02_desenho,y02_desenho);
    glEnd();
    glFlush();
}

void MouseInt (int botao, int estado, int x, int y){
    switch(botao){
       case GLUT_LEFT_BUTTON:
          if(estado == GLUT_DOWN){
             if(cont%2==0){
                x01_desenho = ((float)x/300)-1;
                y01_desenho = -(((float)y/300)-1);
             }
             else{
                x02_desenho = ((float)x/300)-1;
                y02_desenho = -(((float)y/300)-1);
             }
             cont++;
          }
          break;
    }
    if(cont%2==0){
        glutPostRedisplay();
    }
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
