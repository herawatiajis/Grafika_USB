#include <iostream>
#include <GL/freeglut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Bendera hitam (di atas)
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0.10, 0.50);
    glVertex2f(0.10, 0.70);
    glVertex2f(0.80, 0.70);
    glVertex2f(0.80, 0.50);
    glEnd();


    // Bendera putih (di tengah)
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex2f(-1.0, 0.0);
    glVertex2f(1.0, 0.0);
    glVertex2f(1.0, -0.5);
    glVertex2f(-1.0, -0.5);
    glEnd();

    // Bendera hijau (di bawah)
    glColor3f(0.0, 0.2, 0.0);
    glBegin(GL_POLYGON);
    glVertex2f(-1.0, -0.5);
    glVertex2f(1.0, -0.5);
    glVertex2f(1.0, -1.0);
    glVertex2f(-1.0, -1.0);
    glEnd();

    // segitiga ujung merah (di kiri atas)
    glBegin(GL_TRIANGLES);
    glColor3f(0.5, 0.0, 0.0);
    float x1 = -1.0; // Koordinat x titik kiri atas segitiga
    float y1 = 0.99;  // Koordinat y titik kiri atas segitiga
    float x2 = -0.11; // Koordinat x titik tengah bawah segitiga
    float y2 = 0.1;  // Koordinat y titik tengah bawah segitiga
    float x3 = -1.0; // Koordinat x titik kiri bawah segitiga
    float y3 = -1.0;  // Koordinat y titik kiri bawah segitiga

    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glVertex2f(x3, y3);
    glEnd();

    glutSwapBuffers();
}
void reshape(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0); // Mengatur rentang tinggi dan lebar ke -1 hingga 1
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(600, 400);
    glutCreateWindow("Bendera palestina");

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);

    glutMainLoop();
    return 0;
}
