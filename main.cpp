#include<windows.h>
#include<stdio.h>
#include<math.h>
#include<GL/glut.h>
#include<conio.h>
#include<stdlib.h>


int xc = 320 , yc = 240; //center of the circle

void plot_point(int x, int y)
{
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

void brasenham_circle(int r)
{
    int x = 0, y=r;
    float pk = 3-2*r;

    plot_point(x,y);
    int k;

    while(x<=y)
    {
        x = x + 1;
        if(pk < 0){
            pk = pk + 4*x+6;
        }
        else{
            y = y - 1;
            pk = pk + 4*(x-y) + 10;
        }
        plot_point(x,y);
    }
    glFlush();
}

void concentric_circles(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    int radius1 = 150;
    brasenham_circle(radius1);
}

void Init()
{
    glClearColor(1.0,1.0,1.0,0); //background color
    glColor3f(0.0,0.0,0.0); //circle color
    gluOrtho2D(0,640,0,480);
}

int main(int argc, char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(640,480);
    glutCreateWindow("Bresenham_circle");
    Init();
    glutDisplayFunc(concentric_circles);
    glutMainLoop();
    return 0;
}
