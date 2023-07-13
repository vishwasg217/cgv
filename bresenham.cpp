#include<GL/glut.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<math.h>

void myinit() {
    glMatrixMode(GL_PROJECTION_MATRIX);
    glLoadIdentity();
    gluOrtho2D(0, 100, 0, 100);
    glMatrixMode(GL_MODELVIEW);
}
void plot(int x, int y) {
    glPointSize(3);
    glColor3f(1, 0, 0);
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}
void bresenham(int xo, int yo, int xend, int yend) {
    int dx = abs(xend - xo), dy = abs(yend - yo);
    int x, y, twoM = 2 * (dy - dx);
    int p;
    if ((dy / dx) < 1) {
        int p = 2 * dy - dx;
        int twody = 2 * dy, twoM = 2 * (dy - dx);
        if (xo > xend) {
            x = xend;
            y = yend;
            xend = xo;
        }
        else {
            x = xo;
            y = yo;
        }
        plot(x, y);
        while (x < xend) {
            x++;
            if (p < 0) {
                p += twody;
            }
            else {
                y++;
                p += twoM;
            }
            plot(x, y);
        }
    }
    else {
        int twodx = 2 * dx;
        twoM = 2 * (dx-dy);
        p = 2 * dx - dy;
        if (xo > xend) {
            x = xend;
            y = yend;
            xend = xo;
        }
        else {
            x = xo;
            y = yo;
        }
        plot(x, y);
        while (y < yend) {
            y++;
            if (p < 0) {
                p += twodx;
            }
            else {
                x++;
                p += twoM;
            }
            plot(x, y);
        }
    }
}

void disp() {
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    bresenham(0, 0, 10, 10);
    glFlush();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Bresenham Line Drawing Algorithm");
    myinit();
    glutDisplayFunc(disp);
    glutMainLoop();
}