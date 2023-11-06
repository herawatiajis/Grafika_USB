#include <iostream>
#include <GL/freeglut.h>
#include <math.h>
#include <stdio.h>

void init(void);
void display(void);

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(350, 350);
    glutInitWindowPosition(10, 10);
    glutCreateWindow("Perpotongan garis");
    init(); //memanggi fungsi init
    glutDisplayFunc(display);
    glutMainLoop(); //untuk menjalankan program

    return 0;
}

void init(void) {
    glClearColor(11, 1, 1, 0);
    glColor3f(1, 1, 1);
    glMatrixMode(GL_PROJECTION);
    glPointSize(6);
    glLoadIdentity();
    gluOrtho2D(0, 10, 0, 10);
}

void display(void) {
    //garis AB
    float ax = 1;
    float ay = 1;
    float bx = 5;
    float by = 5;

    // garis CD
    float cx = 1;
    float cy = 3;
    float dx = 5;
    float dy = 1;

    float m1, m2, c1, c2, ex, ey;


    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1, 0, 0);

    glBegin(GL_LINES);
    glVertex2f(ax, ay);
    glVertex2f(bx, by);

    glVertex2f(cx, cy);
    glVertex2f(dx, dy);

    glEnd();

    // menentukan persamaan garis 
    // AB
    m1 = (by - ay) / (bx - ax);
    c1 = ay - (m1 * ax);

    // CD
    m2 = (dy - cy) / (dx - cx);
    c2 = cy - (m2 * cx);

    // Menentukan titik potong
    ex = (c2 - c1) / (m1 - m2);
    ey = (m1 * ex) + c1;

    printf("%f,%f", ex, ey);

    glPointSize(6);
    glBegin(GL_POINTS);
    glVertex2f(ex, ey);
    glEnd();


    glFlush();
}





