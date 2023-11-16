#include <iostream>
#include <GL/freeglut.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Gambar segi empat dengan garis-garis di dalamnya
    glBegin(GL_QUADS);
    glVertex2f(-0.5, -0.5);
    glVertex2f(0.5, -0.5);
    glVertex2f(0.5, 0.5);
    glVertex2f(-0.5, 0.5);
    glEnd();

    // Gambar garis horizontal dari tengah ke samping kiri
    for (float y = 0; y > -0.5; y -= 0.1) {
        glColor3f(0.0, 0.0, 0.0);
        glBegin(GL_LINES);
        glVertex2f(-0.5, y);
        glVertex2f(0.5, y);
        glEnd();
    }

    // Gambar garis horizontal dari tengah ke samping kanan
    for (float y = 0; y < 0.5; y += 0.1) {
        glColor3f(0.0, 0.0, 0.0);
        glBegin(GL_LINES);
        glVertex2f(-0.5, y);
        glVertex2f(0.5, y);
        glEnd();
    }

    glFlush();


    // perulangan untuk garis vertikal mulai dari tengah ke kiri
    for (float x = 0; x > -0.5; x -= 0.1) {
        glColor3f(0.0, 0.0, 0.0);
        glBegin(GL_LINES);
        glVertex2f(x, -0.5);
        glVertex2f(x, 0.5);
        glEnd();
    }

    // perulangan untuk garis vertikal mulai dari tengah ke kanan
    for (float x = 0; x < 0.5; x += 0.1) {
        glColor3f(0.0, 0.0, 0.0);
        glBegin(GL_LINES);
        glVertex2f(x, -0.5);
        glVertex2f(x, 0.5);
        glEnd();
    }

    glFlush();

}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("Segi Empat dengan Garis-Garis");
    glutInitWindowSize(60, 80);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

