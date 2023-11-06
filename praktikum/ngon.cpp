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
    glColor3f(0.0, 0.0, 1.0);
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
    /*
    //menggambar garis line strip
    glBegin(GL_LINE_STRIP);
    glVertex2i(20, 10);
    glVertex2i(50, 10);
    glVertex2i(20, 80);
    glVertex2i(50, 80);
    glEnd();
    */
    //menggambar garis line loop
    /*glBegin(GL_LINE_LOOP);
    glVertex2i(20, 10);
    glVertex2i(50, 10);
    glVertex2i(20, 80);
    glVertex2i(50, 80);
    glEnd();
    */
    //menggambar n-gon simetris/beraturan

    glBegin(GL_LINE_LOOP);
    ngon(6, 10, 0, 40, 180); // memanggil fungsi
    /*
    glVertex2f(10 * cos(2 * 3.14159265 * 1 / 6), 10 * sin(2 * 3.14159265 * 1 / 6));
    glVertex2f(10 * cos(2 * 3.14159265 * 2 / 6), 10 * sin(2 * 3.14159265 * 2 / 6));
    glVertex2f(10 * cos(2 * 3.14159265 * 3 / 6), 10 * sin(2 * 3.14159265 * 3 / 6));
    glVertex2f(10 * cos(2 * 3.14159265 * 4 / 6), 10 * sin(2 * 3.14159265 * 4 / 6));
    glVertex2f(10 * cos(2 * 3.14159265 * 5 / 6), 10 * sin(2 * 3.14159265 * 5 / 6));
    glVertex2f(10 * cos(2 * 3.14159265 * 6 / 6), 10 * sin(2 * 3.14159265 * 6 / 6));
    */
    glEnd();


    glutSwapBuffers();
}





