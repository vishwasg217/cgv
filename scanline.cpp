#include<GL/glut.h>
using namespace std;
float et[4][4] = {{100, 200, 250, -1},
                  {100, 200, 250, 1},
                  {200, 300, 150, 1},
                  {200, 300, 350, -1}};
float aet[4][3];
float js = et[0][0],ymax = 0;
int iaet=0, np = 4,i;
float s[4][2] = {{250, 100}, {150, 200}, {250, 300}, {350, 200}};

void addaet(){
    for(int i = 0;i < np;i++){
        if(et[i][0] == js){
            aet[iaet][0] = et[i][1];
            aet[iaet][1] = et[i][2];
            aet[iaet][2] = et[i][3];
        }
        if(aet[iaet][0] > ymax)
            ymax = aet[iaet][0];
        iaet++;
    }
}
void drawPixel(float x1, float x2){
    float x = x1;
    while(x < x2){
        glBegin(GL_POINTS);
        glVertex2f(x, js);
        glEnd();
        glFlush();
        x++;
    }
}
void upaet(){
    for(int i = 0;i < iaet;i++){
        aet[i][1] = aet[i][1] + aet[i][2];
    }
}
void fill(){
    float x[2] = {0, 0};
    do{
        i =0;
        addaet();
        if(aet[0][0] > js){
            x[i] = aet[0][1];
            i++;
        }
        if(aet[1][0] > js){
            x[i] = aet[1][1];
            i++;
        }
        if(aet[2][0] > js){
            x[i] = aet[2][1];
            i++;
        }
        if(aet[3][0] > js){
            x[i] = aet[3][1];
            i++;
        }
        drawPixel(x[0], x[1]);
        upaet();
        js++;
    }while(ymax >= js);
}
void menu(int op){
    if (op == 0){
        glColor3f(1, 0, 0); // Set color to Red
        fill();
    }
    else if (op == 1){
        glColor3f(0, 1, 0); // Set color to Green
        fill();
    }
    else if (op == 2){
        glColor3f(0, 0, 1); // Set color to Blue
        fill();
    }
    glutPostRedisplay();
}
void draw_square()
{
    glBegin(GL_LINE_LOOP);
    glVertex2fv(s[0]);
    glVertex2fv(s[1]);
    glVertex2fv(s[2]);
    glVertex2fv(s[3]);
    glEnd();
    glFlush();
}
void disp(){
    glClearColor(1,1,1,1);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,0,0);
    draw_square();
    glColor3f(1,0 ,0);
    fill();
    glFlush();
}
void myInit(){
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-500,500, -500, 500);
    glMatrixMode(GL_MODELVIEW);
}
int main(int argc, char ** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Scanline");
    myInit();
    
    glutCreateMenu(menu);
    glutAddMenuEntry("Red",0);
    glutAddMenuEntry("Blue", 1);
    glutAddMenuEntry("Green", 2);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutDisplayFunc(disp);
    glutMainLoop();
}