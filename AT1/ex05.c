#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>

float x01_desenho = 0.0;
float y01_desenho = 0.0;
float x02_desenho = 0.0;
float y02_desenho = 0.0;
float x03_desenho = 0.0;
float y03_desenho = 0.0;
int cont = 0;
int modo = 1;

void init(){
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glLineWidth (5);
    glColor3f(1.0,1.0,1.0);
}

void desenho(){
    glClear(GL_COLOR_BUFFER_BIT);
    if(modo==1){
        glBegin(GL_LINES);
            glVertex2f(x01_desenho,y01_desenho);
            glVertex2f(x02_desenho,y02_desenho);
        glEnd();
    }
    if(modo==2){
        glBegin(GL_TRIANGLES);
            glVertex2f(x01_desenho,y01_desenho);
            glVertex2f(x02_desenho,y02_desenho);
            glVertex2f(x03_desenho,y03_desenho);
        glEnd();
    }
    glFlush();
}

void MouseInt (int botao, int estado, int x, int y){
    switch(botao){
       case GLUT_LEFT_BUTTON:
          if(estado == GLUT_DOWN){
             if(modo==1){
                if(cont%2==0){
                    x01_desenho = ((float)x/300)-1;
                    y01_desenho = -(((float)y/300)-1);
                }
                else{
                    x02_desenho = ((float)x/300)-1;
                    y02_desenho = -(((float)y/300)-1);
                }
                cont++;
                if(cont%2==0)
                    glutPostRedisplay();
             }
             if(modo==2){
                if(cont%3==0){
                    x01_desenho = ((float)x/300)-1;
                    y01_desenho = -(((float)y/300)-1);
                }
                else{
                    if(cont%3==1){
                        x02_desenho = ((float)x/300)-1;
                        y02_desenho = -(((float)y/300)-1);
                    }
                    else{
                        x03_desenho = ((float)x/300)-1;
                        y03_desenho = -(((float)y/300)-1);
                    }
                }
                cont++;
                if(cont%3==0)
                    glutPostRedisplay();
             }
          }
          break;
    }
}

void Keyboard (unsigned char key, int x, int y){
    switch(key){
       case 'R':
       case 'r':
           modo = 1;
           cont = 0;
           x01_desenho = 0.0;
           y01_desenho = 0.0;
           x02_desenho = 0.0;
           y02_desenho = 0.0;
           break;
       case 'T':
       case 't':
           modo = 2;
           cont = 0;
           x01_desenho = 0.0;
           y01_desenho = 0.0;
           x02_desenho = 0.0;
           y02_desenho = 0.0;
           x03_desenho = 0.0;
           y03_desenho = 0.0;
           break;
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
