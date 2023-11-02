#include <iostream>
#include <GL/freeglut.h>


void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Bendera putih
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(-1.0, -0.5);
    glVertex2f(1.0, -0.5);
    glVertex2f(1.0, 0.5);
    glVertex2f(-1.0, 0.5);
    glEnd();

    // Bendera merah
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(-1.0, 0.0);  // Titik kiri bawah (tetap di tengah)
    glVertex2f(1.0, 0.0);   // Titik kanan bawah (tetap di tengah)
    glVertex2f(1.0, 0.5);   // Titik kanan atas (setengah bagian atas layar)
    glVertex2f(-1.0, 0.5);  // Titik kiri atas (setengah bagian atas layar)
    glEnd();

    glutSwapBuffers();
}

void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -0.5, 0.5);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(4000, 2000);
    glutCreateWindow("Bendera Indonesia");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glutMainLoop();
    return 0;
}