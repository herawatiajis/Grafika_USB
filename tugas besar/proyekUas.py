from OpenGL.GL import *
from OpenGL.GLUT import *
from OpenGL.GLU import *
import math

p = -10.0
sun_x = 85.0
sun_y = 65.0
geser = True
a = 0
b = 0
rotasi = 0
black_object_rotation = 0.0

# garis dua titik
def drawLine(x1, y1, x2, y2):
    glBegin(GL_LINES)
    glVertex2f(x1, y1)
    glVertex2f(x2, y2)
    glEnd()

# menggambar lingkaran
def makeCircle(r, x_center, y_center):
    deg = 0
    theta, x, y = 0, 0, 0

    glPointSize(4)
    glBegin(GL_POLYGON)

    while deg < 360:
        theta = (deg * math.pi) / 180
        x = x_center + r * math.cos(theta)
        y = y_center + r * math.sin(theta)
        glVertex2f(x, y)
        deg += 1
    glEnd()

# menggambar rumah
def house(x, y):
    glBegin(GL_QUADS)

    #atap
    glColor3f(0.6, 0.3, 0.2)
    glVertex2f(x, y)
    glVertex2f(x + 20, y)
    glVertex2f(x + 20, y + 20)
    glVertex2f(x, y + 20)
    glEnd()

    # pintu kiri
    glBegin(GL_QUADS)
    glColor3f(0.4, 0.2, 0.1)
    glVertex2f(x + 8, y)
    glVertex2f(x + 3, y)
    glVertex2f(x + 3, y + 10)
    glVertex2f(x + 8, y + 10)
    glEnd()

    # jendela kiri
    glBegin(GL_QUADS)
    glColor3f(0.4, 0.6, 0.8)
    glVertex2f(x + 10, y + 8)
    glVertex2f(x + 10, y + 12)
    glVertex2f(x + 13, y + 12)
    glVertex2f(x + 13, y + 8)
    glEnd()

    # jendela kanan
    glBegin(GL_QUADS)
    glColor3f(0.4, 0.6, 0.8)
    glVertex2f(x + 15, y + 8)
    glVertex2f(x + 15, y + 12)
    glVertex2f(x + 18, y + 12)
    glVertex2f(x + 18, y + 8)
    glEnd()

    #pintu
    glBegin(GL_TRIANGLES)
    glColor3f(0.8, 0.2, 0.2)
    glVertex2f(x - 2, y + 20)
    glVertex2f(x + 22, y + 20)
    glVertex2f(x + 10, y + 30)
    glEnd()

# membuat objek dengan open GL
def drawShapes():
    global p, sun_x, sun_y, rotasi, b, black_object_rotation
    glClear(GL_COLOR_BUFFER_BIT)

    glColor3f(0.0, 0.0, 0.0)
    glPointSize(5.0)

    house(40, 30)

    glutSwapBuffers()
    glFlush()

# pengaturan open GL
def init():
    glClearColor(0.8, 1.0, 1.0, 0.0)
    glMatrixMode(GL_PROJECTION)
    gluOrtho2D(0.0, 100.0, 0.0, 80.0)

def special_keys(key, x, y):
    global sun_x, sun_y
    step = 1.0

    if key == GLUT_KEY_LEFT:
        sun_x -= step
    elif key == GLUT_KEY_RIGHT:
        sun_x += step
    elif key == GLUT_KEY_UP:
        sun_y -= step
    elif key == GLUT_KEY_DOWN:
        sun_y += step
    glutPostRedisplay()

# membuat window
def main():
    glutInit(sys.argv)
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB)
    glutInitWindowPosition(50, 100)
    glutInitWindowSize(1100, 800)
    glutCreateWindow("Rumah")
    init()
    glutDisplayFunc(drawShapes)
    glutSpecialFunc(special_keys)
    glutMainLoop()

main()
