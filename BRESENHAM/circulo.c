//#include <windows.h>
#include <GL/glut.h>
#include <stdio.h>
#include <math.h>

int xc = 250,
    yc = 250,
    raio = 100,
    count = 0,
    xA = 0,
    xB = 0,
    yA = 0,
    yB = 0;

// Center of the cicle = (320, 240)


// Plot eight points using circle's symmetrical property
void plot_point(int x, int y){
  glBegin(GL_POINTS);
      glVertex2i(xc+x, yc+y);
      glVertex2i(xc+x, yc-y);
      glVertex2i(xc+y, yc+x);
      glVertex2i(xc+y, yc-x);
      glVertex2i(xc-x, yc-y);
      glVertex2i(xc-y, yc-x);
      glVertex2i(xc-x, yc+y);
      glVertex2i(xc-y, yc+x);
  glEnd();
}

// Function to draw a circle using bresenham's
// circle drawing algorithm
void circuloBresenham(){
    int x = 0;
    int y = raio;
    float pk = (5.0/4.0)-raio;

    /* Plot the points */
    /* Plot the first point */
    plot_point(x,y);
    /* Find all vertices till x=y */
    while(x < y){
        x = x + 1;
        if(pk < 0)
        pk = pk + 2*x+1;
        else{
            y = y - 1;
            pk = pk + 2*(x - y) + 1;
        }
        plot_point(x,y);
    }
    glFlush();
}

void Init(){
  glClear(GL_COLOR_BUFFER_BIT);
  glClearColor(0,0,0,1);
  gluOrtho2D(0 ,500 , 0,500);
}

void mouseInt(int botao, int estado, int x, int y){
    switch(botao){
       case GLUT_LEFT_BUTTON:
          if(estado == GLUT_DOWN){
             if(count%2 == 0){
                xA = x;
                yA = 500-y;
                xc = xA; yc = yA;
             }
             else{
                xB = x;
                yB = 500-y;
                raio = sqrt((xB-xA)*(xB-xA)+(yB-yA)*(yB-yA));
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

int main(int argc, char **argv){
    /* Initialise GLUT library */
    glutInit(&argc,argv);
    /* Set the initial display mode */
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    /* Set the initial window position and size */
    glutInitWindowPosition(0,0);
    glutInitWindowSize(500,500);
    /* Create the window with title "DDA_Line" */
    glutCreateWindow("bresenham_circle");
    /* Initialize drawing colors */
    Init();
    /* Call the displaying function */
    glutDisplayFunc(circuloBresenham);
    glutMouseFunc(mouseInt);
    /* Keep displaying untill the program is closed */
    glutMainLoop();
    return 0;
}
