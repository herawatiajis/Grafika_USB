#include <iostream>
#include <GL/freeglut.h>
#include <math.h>

void init(void);
void display(void);

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(250, 250);
    glutCreateWindow("n-gon beraturan lingkarang");
    init(); //memanggi fungsi init
    glutDisplayFunc(display);
    glutMainLoop(); //untuk menjalankan program

    return 0;
}

void init(void) {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    //glColor3f(0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-100.0, 100.0, -100.0, 100.0, -100.0, 100.0);
}

void ngon(int n, float cx, float cy, float radius, float rotAngle) {
    double angle, angleInc;
    int k;

    if (n < 3) return;
    angle = rotAngle * 3.14159265 / 180;
    angleInc = 2 * 3.14159265 / n;

    //titik pertama
    glVertex2f(radius * cos(angle) + cy, radius * sin(angle) + cy);

    // titik berikutnya
    for (k = 0; k < n; k++) {
        angle += angleInc;
        glVertex2f(radius * cos(angle) + cy, radius * sin(angle) + cy);

    }
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    // int segi = 6;
    /*for (int a = 60; a >= 30; a-= 10)
     {
         if (segi % 2 == 0) {
             glBegin(GL_LINE_LOOP);
                 glColor3f(1.0, 0.0, 0.0);
                 ngon(segi, 0, 0, a, 45); // memanggil fungsi
             glEnd();
         }
         else{
             glBegin(GL_LINE_LOOP);
                 glColor3f(0.0, 0.0, 1.0);
                 ngon(segi, 0, 0, a, 45); // memanggil fungsi
             glEnd();
         }
         segi--;
         */



    int data[3][2] = { { 0,-40 }, {0, 40}, {80, 80} };
    glBegin(GL_LINE_LOOP);
    glColor3f(1.0, 0.0, 0.0);
    for (int s = 0; s < 3; s++) {
        glVertex2i(data[s][0], data[s][1]);
    }

    glEnd();
    glutSwapBuffers();
}





