#include <windows.h>
#include <gl/gl.h>
#include <GL/glut.h>
#include <math.h>
#include <stdio.h>

float t=0.0;
float r=0.0;
int n = 100;
float ang = 0;

void init(){
    glClearColor(0, 0, 0, 0); //Preto
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluOrtho2D(-6.0,6.0,-6.0,6.0);
}

void petalas(){
    int i;



    glPushMatrix(); {

    glRotatef(r,0,0,1);
    //PETALA 1
    glPushMatrix();
    glTranslatef(1.0,0.0,0.0);
    glColor3f(0.0,1.0,0.0);
    glBegin(GL_POLYGON);
        for(i=0;i<n;i++){
            glVertex2f(cos(ang),sin(ang));
            ang = ang+(2*M_PI)/n;
        }
    glEnd();
    glColor3f(0.5,0.5,0.0);
    glBegin(GL_POLYGON);
        for(i=0;i<n;i++){
            glVertex2f(0.7*cos(ang),0.7*sin(ang));
            ang = ang+(2*M_PI)/n;
        }
    glEnd();
    glPopMatrix();
//PETALA 2
    glPushMatrix();
    glTranslatef(-1.0,0.0,0.0);
    glColor3f(0.0,1.0,0.0);
    glBegin(GL_POLYGON);
    for(i=0;i<n;i++){
        glVertex2f(cos(ang),sin(ang));
        ang = ang+(2*M_PI)/n;
    }
    glEnd();
    glColor3f(0.5,0.5,0.0);
    glBegin(GL_POLYGON);
        for(i=0;i<n;i++){
            glVertex2f(0.7*cos(ang),0.7*sin(ang));
            ang = ang+(2*M_PI)/n;
        }
    glEnd();
    glPopMatrix();
//PETALA 3
    glPushMatrix();
    glTranslatef(0.0,1.0,0.0);
    glColor3f(0.0,1.0,0.0);
    glBegin(GL_POLYGON);
        for(i=0;i<n;i++){
            glVertex2f(cos(ang),sin(ang));
            ang = ang+(2*M_PI)/n;
        }
    glEnd();
    glColor3f(0.5,0.5,0.0);
    glBegin(GL_POLYGON);
        for(i=0;i<n;i++){
            glVertex2f(0.7*cos(ang),0.7*sin(ang));
            ang = ang+(2*M_PI)/n;
        }
    glEnd();
    glPopMatrix();
//PETALA 4
    glPushMatrix();
    glTranslatef(0.0,-1.0,0.0);
    glColor3f(0.0,1.0,0.0);
    glBegin(GL_POLYGON);
        for(i=0;i<n;i++){
            glVertex2f(cos(ang),sin(ang));
            ang = ang+(2*M_PI)/n;
        }
    glEnd();
    glColor3f(0.5,0.5,0.0);
    glBegin(GL_POLYGON);
        for(i=0;i<n;i++){
            glVertex2f(0.7*cos(ang),0.7*sin(ang));
            ang = ang+(2*M_PI)/n;
        }
    glEnd();
    glPopMatrix();

   } glPopMatrix();

}

void desenha(){
    int i;
    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix(); {

    glRotatef(r,0,0,1);

//PETALA 1
    glPushMatrix();
    glTranslatef(1.0,1.0,0.0);
    glColor3f(0.0,1.0,0.0);
    glBegin(GL_POLYGON);
        for(i=0;i<n;i++){
            glVertex2f(cos(ang),sin(ang));
            ang = ang+(2*M_PI)/n;
        }
    glEnd();
    glColor3f(0.5,0.5,0.0);
    glBegin(GL_POLYGON);
        for(i=0;i<n;i++){
            glVertex2f(0.7*cos(ang),0.7*sin(ang));
            ang = ang+(2*M_PI)/n;
        }
    glEnd();
    glPopMatrix();
//PETALA 2
    glPushMatrix();
    glTranslatef(-1.0,-1.0,0.0);
    glColor3f(0.0,1.0,0.0);
    glBegin(GL_POLYGON);
    for(i=0;i<n;i++){
        glVertex2f(cos(ang),sin(ang));
        ang = ang+(2*M_PI)/n;
    }
    glEnd();
    glColor3f(0.5,0.5,0.0);
    glBegin(GL_POLYGON);
        for(i=0;i<n;i++){
            glVertex2f(0.7*cos(ang),0.7*sin(ang));
            ang = ang+(2*M_PI)/n;
        }
    glEnd();
    glPopMatrix();
//PETALA 3
    glPushMatrix();
    glTranslatef(1.0,-1.0,0.0);
    glColor3f(0.0,1.0,0.0);
    glBegin(GL_POLYGON);
        for(i=0;i<n;i++){
            glVertex2f(cos(ang),sin(ang));
            ang = ang+(2*M_PI)/n;
        }
    glEnd();
    glColor3f(0.5,0.5,0.0);
    glBegin(GL_POLYGON);
        for(i=0;i<n;i++){
            glVertex2f(0.7*cos(ang),0.7*sin(ang));
            ang = ang+(2*M_PI)/n;
        }
    glEnd();
    glPopMatrix();
//PETALA 4
    glPushMatrix();
    glTranslatef(-1.0,1.0,0.0);
    glColor3f(0.0,1.0,0.0);
    glBegin(GL_POLYGON);
        for(i=0;i<n;i++){
            glVertex2f(cos(ang),sin(ang));
            ang = ang+(2*M_PI)/n;
        }
    glEnd();
    glColor3f(0.5,0.5,0.0);
    glBegin(GL_POLYGON);
        for(i=0;i<n;i++){
            glVertex2f(0.7*cos(ang),0.7*sin(ang));
            ang = ang+(2*M_PI)/n;
        }
    glEnd();
    glPopMatrix();

   } glPopMatrix();

   petalas();

    glColor3f(1.0,1.0,0.0);
    glBegin(GL_POLYGON);
        for(i=0;i<n;i++){
            glVertex2f(cos(ang),sin(ang));
            ang = ang+(2*M_PI)/n;
        }
    glEnd();

    glFlush();
}

void Keyboard (unsigned char key, int x, int y){
    switch(key){
       case 'd':
       case 'D':
          t=t+0.25;
          r=r+20;
          break;
       case 'e':
       case 'E':
          t=t-0.25;
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
    glutDisplayFunc (desenha);
    glutKeyboardFunc(Keyboard);
    glutMainLoop ();
    return 0;
}
