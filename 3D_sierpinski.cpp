#include<stdio.h>
#include<GL/glut.h>

void myInit();
void display();
void divide_tetrahedron(float *a, float *b, float *c, float *d, int m);
void draw_tetra(float *a, float *b,float*c, float *d);
void draw_triangle(float *a, float *b, float *c);

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(500,500);
    glutCreateWindow("3D Sierpinski Gasket");
    myInit();
    glutDisplayFunc(display);
    glEnable(GL_DEPTH_TEST);
    glutMainLoop();
}
void myInit()
{
    glMatrixMode(GL_PROJECTION_MATRIX);
    glLoadIdentity();
    glOrtho(-2, +2, -2, +2, -2, +2);
    glMatrixMode(GL_MODELVIEW);
}
void display()
{
    glClearColor(0,0,0,1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    int n = 2;
    float v[4][3] = {{-0.5, -0.25, 0},
                    {0, 0.75, 0},
                    {0.5, -0.25, 0},
                    {0, 0, 0.25}};
    divide_tetrahedron(v[0], v[1], v[2], v[3], n);
    glFlush();
}

void divide_tetrahedron(float *a, float *b, float *c, float *d, int m)
{
    float ab[3], ad[3], bd[3], ac[3], bc[3], cd[3];
    int j;
    if(m > 0){
        for(j = 0;j < 3;j++){
            ab[j] = (a[j] + b[j])/2;
            ad[j] = (a[j] + d[j])/2;
            ac[j] = (a[j] + c[j])/2;
            bd[j] = (b[j] + d[j])/2;
            bc[j] = (b[j] + c[j])/2;
            cd[j] = (c[j] + d[j])/2;
        }
        divide_tetrahedron(a,ab,ac,ad,m-1);
        divide_tetrahedron(ab,b,bc,bd,m-1);
        divide_tetrahedron(cd,bc,c,ac,m-1);
        divide_tetrahedron(ad,bd,cd,d,m-1);
    }
    else    
        draw_tetra(a, b, c, d);
}
void draw_tetra(float *a, float *b,float*c, float *d){
    glColor3f(1,0,0);
    draw_triangle(a,b,c);

    glColor3f(0,1,0);
    draw_triangle(a,d,c);

    glColor3f(1,0.5,0);
    draw_triangle(d,b,c);

    glColor3f(1,1,0);
    draw_triangle(a,b,d);
}
void draw_triangle(float *a, float *b, float *c)
{
    glBegin(GL_POLYGON);
    glVertex3fv(a);
    glVertex3fv(b);
    glVertex3fv(c);
    glEnd();
}