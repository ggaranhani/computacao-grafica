//#include <windows.h>
//#include <gl/gl.h>
#include <GL/glut.h>
#include <math.h>
#include <stdio.h>

float t=0.0;
float r=0.0;
float tam = 0.4;
int n = 100;
float ang = 0;

void init(){
    glClearColor(0, 0, 0, 0); //Preto
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluOrtho2D(-15.0,15.0,-15.0,15.0);
}

void petala(int x, int y, float r){
    int i;
    glPushMatrix();
    glBegin(GL_POLYGON);
        for(i=0;i<n;i++){
            glVertex2f(r*cos(ang)+x,r*sin(ang)+y);
            ang = ang+(2*M_PI)/n;
        }
    glEnd();
    glPopMatrix();
}


void quadrado(){
    glBegin(GL_POLYGON);
        glVertex2f(-0.5, 0.5);
        glVertex2f(0.5, 0.5);
        glVertex2f(0.5, -0.5);
        glVertex2f(-0.5, -0.5);
    glEnd();
}

void desenha4(){
    glClear(GL_COLOR_BUFFER_BIT);


        glColor3f(0.0,0.0,1.0);


    glPushMatrix();
        glTranslatef(2+t,2,0);
        glRotatef(r,0.0,0.0,1.0);
        quadrado();
    glPopMatrix();

    glFlush();
}

void desenha2(){
    int i;
    glClear(GL_COLOR_BUFFER_BIT);
    tam = 1.0;
    carroceria();
    roda(-8);
    roda(8);

    glFlush();
}

void carroceria(){
    glColor3f(1,1,1);

    glPushMatrix(); {
        glTranslatef(t,0,0);
        glBegin(GL_POLYGON);
            glVertex2f(-12, 5);
            glVertex2f(12, 5);
            glVertex2f(12, 1);
            glVertex2f(-12, 1);
        glEnd();
        glBegin(GL_POLYGON);
            glVertex2f(-10, 10);
            glVertex2f(6, 10);
            glVertex2f(6, 5);
            glVertex2f(-10, 5);
        glEnd();
    } glPopMatrix();

}

void roda(int x){
    int i;
    glColor3f(0.1,0.1,0.1);
    glPushMatrix(); {

        glTranslatef(-x+t,0,0);
        glRotatef(r,0,0,1);

        glBegin(GL_POLYGON);
            for(i=0;i<n;i++){
                glVertex2f(3*cos(ang),3*sin(ang));
                ang = ang+(2*M_PI)/n;
            }
        glEnd();

        glColor3f(0.0,1.0,0.0);
        petala(tam,tam,tam);

    //PETALA 2
        glColor3f(0.0,1.0,0.0);
        petala(-tam,-tam,tam);

    //PETALA 3
        glColor3f(0.0,1.0,0.0);
        petala(tam,-tam,tam);

    //PETALA 4
        glColor3f(0.0,1.0,0.0);
        petala(-tam,tam,tam);

        glColor3f(1.0,1.0,0.0);
        glBegin(GL_POLYGON);
            for(i=0;i<n;i++){
                glVertex2f(cos(ang),sin(ang));
                ang = ang+(2*M_PI)/n;
            }
        glEnd();

   } glPopMatrix();
}

void Keyboard (unsigned char key, int x, int y){
    switch(key){
       case 'a':
       case 'A':
          t=t - 0.25;
          r=r+20;
          break;
       case 'd':
       case 'D':
          t=t + 0.25;
          r=r-20;
          break;
    }
    printf("t: %f\n", t);
    glutPostRedisplay();
}

int main ( int argc , char * argv [] ){
    glutInit(&argc , argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition (50 ,100);
    glutInitWindowSize (600 ,600);
    glutCreateWindow ("flor pra que te quero");
    init();
    glutDisplayFunc (desenha2);
    glutKeyboardFunc(Keyboard);
    glutMainLoop ();
    return 0;
}




