#include<GL/glut.h>
#include<stdio.h>
#include<math.h>
using namespace std;
float tri[3][3] = {{20, 20}, {40, 40},{60, 20}};
float theta = 45, rtheta;
void draw_tri(){
    
    glBegin(GL_TRIANGLES);
    glVertex2fv(tri[0]);
    glVertex2fv(tri[1]);
    glVertex2fv(tri[2]);
    glEnd();
}
void rotate_tri(int xp, int yp){
    glColor3f(1,0,0);
    draw_tri();
    int x, y;
    rtheta = (theta * 3.14)/180;
    for(int i = 0; i < 3;i++){
        x = tri[i][0];
        y = tri[i][1];
        tri[i][0] = xp + (x - xp)*cos(rtheta) - (y - yp) * sin(rtheta);
        tri[i][1] = yp + (x - xp)*sin(rtheta) + (y - yp) * sin(rtheta);
    }
    glColor3f(1,1,0);
    draw_tri();
}
void disp(){
    glClearColor(1,1,1,1);
    glClear(GL_COLOR_BUFFER_BIT);
    rotate_tri(20, 20);
    glFlush();
}
void myInit(){
    glMatrixMode(GL_PROJECTION_MATRIX);
    glLoadIdentity();
    gluOrtho2D(-100, 100, -100, 100);
    glMatrixMode(GL_MODELVIEW);
}
int main(int argc, char **argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Rotate triangle");
    myInit();
    glutDisplayFunc(disp);
    glutMainLoop();
}