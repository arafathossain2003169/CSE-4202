#include <GL/gl.h>
#include <GL/glu.h>
#include <Gl/glut.h>
#include <bits/stdc++.h>
using namespace std;

float x_1, y_1, x_2, y_2;
void display();
void reshape(int, int);

pair<int , int> scan_convert(float x, float y)
{
    return make_pair(round(x), round(y));

}

float find_m(pair<int, int>p1, pair<int, int>p2)
{
    float m = (float)(p2.second - p1.second)/(p2.first - p1.first);
    return m;
}

float find_b(pair<int, int>p, float m)
{
    float b = p.second - m*p.first;
    return b;
}

pair<int, int> find_y(float m, float x, float b)
{
    float y = m*x + b;
    return scan_convert(x, y);
}

pair<int, int> find_x(float m, float y, float b)
{
    float x = (y-b)/m;
    return scan_convert(x, y);
}

void draw_point(pair<int, int>p)
{
    glVertex2i(p.first, p.second);
}

void direct(float x1, float y1, float x2, float y2)
{
    pair<int, int> p1 = scan_convert(x1, y1);
    pair<int, int> p2 = scan_convert(x2, y2);
    if((p2.first - p1.first) == 0)
    {
        if(p1.second > p2.second) swap(p1, p2);
        for(int y = p1.second; y <= p2.second; y++)
        {
            int x = p1.first;
            draw_point(make_pair(x, y));
        }
        return;
    }
    float m = find_m(p1, p2);
    float b = find_b(p1, m);
    if(abs(m) < 1)
    {
        if(p1.first > p2.first) swap(p1, p2);
        for(int x = p1.first; x <= p2.first; x++) draw_point(find_y(m, x, b));
    }
    else
    {
        if(p1.second > p2.second) swap(p1, p2);
        for(int y = p1.second; y <= p2.second; y++) draw_point(find_x(m, y, b));
    }
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

    cout<<"Enter starting point (x1, y1): ";
    cin>>x_1 >>y_1;
    cout<<"Enter ending point (x2, y2): ";
    cin>>x_2>>y_2;
    glutCreateWindow("Line Conversion");

    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);


    glutMainLoop();

}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();


    glPointSize(1.0);
    // draw
    glBegin(GL_POINTS);
    //
    direct(x_1, y_1, x_2, y_2);
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
