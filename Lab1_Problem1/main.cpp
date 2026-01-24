#include <GL/gl.h>
#include <GL/glu.h>
#include <Gl/glut.h>
#include <bits/stdc++.h>
using namespace std;

float x, y;
void display();
void reshape(int, int);

pair<int , int> scan_convert(float x, float y)
{
    return make_pair(round(x), round(y));

}

void draw_point(pair<int, int>p)
{
    glVertex2i(p.first, p.second);
}

void init()
{
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glColor3f(0.0, 0.0, 0.0);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);

    glutInitWindowPosition(200, 100);
    glutInitWindowSize(500, 500);

    cout<<"Enter (x, y): ";
    cin>>x>>y;

    glutCreateWindow("Scan Convert");

    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);


    glutMainLoop();

}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();


    glPointSize(10.0);
    // draw
    glBegin(GL_POINTS);
    //
    draw_point(scan_convert(x, y));
    glEnd();

    glFlush();

}

void reshape(int w, int h)
{
    //viewport
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    //projection
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, w, 0, h);
    glMatrixMode(GL_MODELVIEW);
}
