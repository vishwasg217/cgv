#include<GL/glut.h>
#include<stdio.h>
#include<math.h>
float v[8][3] = {{-1,-1,1}, {-1,1,1}, {1,1,1}, {1,-1,1},{-1,-1,-1}, {-1,1,-1}, {1,1,-1}, {1,-1,-1}};
float c[8][3] = {{0,0,1}, {0,1,1}, {1,1,1}, {1,0,1}, {0,0,0}, {0,1,0}, {1,1,0}, {1,0,0}};
int flag = 0;
int theta[3] = {0, 0, 0};
using namespace std;
void drawPoly(int a,int b, int c1, int d){
    glBegin(GL_POLYGON);
    glColor3fv(c[a]);
    glVertex3fv(v[a]);

    glColor3fv(c[b]);
    glVertex3fv(v[b]);

    glColor3fv(c[c1]);
    glVertex3fv(v[c1]);

    glColor3fv(c[d]);
    glVertex3fv(v[d]);

    glEnd();
}
void colorcube(){
    drawPoly(0,1,2,3);
    drawPoly(0,1,5,4);
    drawPoly(1,5,6,2);
    drawPoly(4,5,6,7);
    drawPoly(3,2,6,7);
    drawPoly(0,4,7,3);
}
void mouse(int b, int s, int x, int y){
    if(b == GLUT_RIGHT_BUTTON && s == GLUT_DOWN){
        flag = 0;
    }
    if(b == GLUT_RIGHT_BUTTON && s == GLUT_DOWN){
        flag = 1;
    }
    if(b == GLUT_RIGHT_BUTTON && s == GLUT_DOWN){
        flag = 2;
    }
}
void idle(){
    theta[flag] += 5;
    if(theta[flag] > 360)
        theta[flag] = 0;
    glutPostRedisplay();
}
void disp(){
    glClearColor(1,1,1,1);
    glClear(GL_COLOR_BUFFER_BIT);
    glRotatef(theta[2], 0, 0, 1);
    glRotatef(theta[1], 0, 1, 0);
    glRotatef(theta[0], 1, 0, 0);
    colorcube();
    glFlush();
}
void myInit(){
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-2,2,-2,2,-2,2);
    glMatrixMode(GL_MODELVIEW);
}
int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE | GLUT_DEPTH);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Rotate cube");
    myInit();
    glutDisplayFunc(disp);
    glutMouseFunc(mouse);
    glutIdleFunc(idle);
    glutMainLoop();
}