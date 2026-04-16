#include <GL/glut.h>
#include <iostream>

// Window size
const int WIDTH = 600;
const int HEIGHT = 600;


GLfloat angle = 0.0f;
GLfloat tx = 0.0f, ty = 0.0f;
GLfloat scale = 1.0f;


GLfloat dx = 0.1f;
GLfloat dy = 0.1f;

// Display function
void display() {
    glMatrixMode(GL_MODELVIEW);
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    // Apply transformations
    glTranslatef(tx, ty, 0.0f);
    glRotatef(angle, 0.0f, 0.0f, 1.0f);
    glScalef(scale, scale, 1.0f);

    // Draw rectangle
    glColor3f(1.0f, 0.0f, 0.0f);

    glBegin(GL_LINE_LOOP);
        glVertex2f(-2.0f, -2.0f);
        glVertex2f( 2.0f, -2.0f);
        glVertex2f( 2.0f,  2.0f);
        glVertex2f(-2.0f,  2.0f);
    glEnd();

    glFlush();
}


void timer(int value) {
    
    // angle += 2.0f;

    
    tx += dx;
    ty += dy;

    
    if (tx > 8 || tx < -8) dx = -dx;
    if (ty > 8 || ty < -8) dy = -dy;

    glutPostRedisplay();
    glutTimerFunc(16, timer, 0); 
}

// Keyboard (normal keys)
void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 'a':   // Rotate left
            angle += 10;
            break;

        case 'd':   // Rotate right
            angle -= 10;
            break;

        case 'j':   // Scale up
            scale += 0.1f;
            break;

        case 'l':   // Scale down
            scale -= 0.1f;
            if (scale < 0.1f) scale = 0.1f;
            break;

        case 27: // ESC
            exit(0);
    }

    glutPostRedisplay();
}

// Special keys (arrow keys)
void specialKeys(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_UP:
            ty += 0.5f;
            break;

        case GLUT_KEY_DOWN:
            ty -= 0.5f;
            break;

        case GLUT_KEY_LEFT:
            tx -= 0.5f;
            break;

        case GLUT_KEY_RIGHT:
            tx += 0.5f;
            break;
    }

    glutPostRedisplay();
}

// Resize function
void resized(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-10, 10, -10, 10);
}

// Init
void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
}

// Main
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);

    glutInitWindowSize(WIDTH, HEIGHT);
    glutCreateWindow("Animated Rectangle");

    init();

    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(specialKeys);
    glutReshapeFunc(resized);

    // Start animation
    glutTimerFunc(0, timer, 0);

    glutMainLoop();
    return 0;
}