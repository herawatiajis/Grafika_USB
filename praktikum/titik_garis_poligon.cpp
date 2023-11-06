#include <iostream>
#include <GL/freeglut.h>


void init(void);
void display(void);

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(250, 250);
    glutCreateWindow("titik, garis dan poligon");
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
    glOrtho(-10.0, 10.0, -10.0, 10.0, -10.0, 10.0);
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);

    //menggambar titik
    glBegin(GL_POINTS);
    glVertex3i(1, 4, 0);
    glVertex3i(5, 8, 0);
    glEnd();

    //menggambar garis
    glBegin(GL_LINES);
    glVertex3i(1, 4, 0);
    glVertex3i(5, 8, 0);
    glVertex3i(6, -8, 0);
    glEnd();

    //menggambar segitiga
    glBegin(GL_TRIANGLES);
    glVertex3i(1, 4, 0);
    glVertex3i(5, 8, 0);
    glVertex3i(6, -8, 0);
    glEnd();

    //menggambar DENGAN 4 TITIK
    glBegin(GL_QUADS);
    glVertex3i(-7, 4, 0);
    glVertex3i(-5, 3, 0);
    glVertex3i(7, -8, 0);
    glVertex3i(2, 6, 0);
    glEnd();

    //menggambar poligon
    glBegin(GL_POLYGON);
    glVertex3i(-7, 4, 0);
    glVertex3i(-5, 3, 0);
    glVertex3i(7, -8, 0);
    glVertex3i(2, 6, 0);
    glEnd();

    glutSwapBuffers();
}

