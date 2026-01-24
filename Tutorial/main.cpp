#include <GL/gl.h>
#include <GL/glu.h>
#include <Gl/glut.h>
#include <bits/stdc++.h>
using namespace std;

void display();
void reshape(int, int);

pair<int , int> scan_convert(float x, float y)
{
    return make_pair(round(x), round(y));

}

float find_m(pair<int, int>p1, pair<int, int>p2)
{
    int dy = p2.second - p1.second;
    int dx = p2.first - p1.first;
    float m = (float)dy/dx;
    cout<<m<<endl;
    return m;
}

void draw_point(pair<int, int>p)
{
    glVertex2i(p.first, p.second);
}

void draw_line(pair<int, int>p1, pair<int, int>p2)
{
    draw_point(p1);
    float x = p1.first, y = p1.second;

    float m = find_m(p1, p2);
    if(abs(m) < 1)
    {
        cout << "yi+1" << endl;
        for(int xi_1 = p1.first + 1; xi_1 <= p2.first; xi_1++)
        {
            float yi_1 = y + m;
            draw_point(scan_convert(xi_1, yi_1));
            y = yi_1;

        }
    }
    else
    {
        cout<<"xi+1"<<endl;
        for(int yi_1 = p1.second + 1; yi_1 <= p2.second; yi_1++)
        {
            float xi_1 = x + 1/m;
            draw_point(scan_convert(xi_1, yi_1));
            x = xi_1;
        }
    }
}

void direct(float x1, float y1, float x2, float y2)
{
    pair<int, int> p1 = scan_convert(x1, y1);
    pair<int, int> p2 = scan_convert(x2, y2);


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



    glutCreateWindow("Window 1");

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
    pair<int, int> p1 = {200, 85};
    pair<int, int> p2 = {460, 106.4};
    pair<int, int> p3 = {460, 256.4};
    pair<int, int> p4 = {200, 300};
    pair<int, int> p5 = {400, 100};
    draw_line(p1, p2);
    draw_line(p1, p3);
    draw_line(p4, p5);
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
