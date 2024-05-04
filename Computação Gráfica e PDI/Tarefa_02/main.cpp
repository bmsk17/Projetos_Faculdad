#include <GL/gl.h>
#include <GL/glut.h>
#include <cmath>

float translacaoX = 0.0;
float fatorEscala = 1.0;
float anguloRotacao = 0.0;

void inicializa() {
    glClearColor(1.0, 1.0, 1.0, 1.0);
    gluOrtho2D(-7.0, 7.0, -5.0, 5.0);
}

void quadrado(float r, float g, float b) {
    glColor3f(r, g, b);
    glBegin(GL_QUADS);
    glVertex2f(-0.75, -0.75);
    glVertex2f(-0.75, 0.75);
    glVertex2f(0.75, 0.75);
    glVertex2f(0.75, -0.75);
    glEnd();
}

void triangulo(float r, float g, float b) {
    glColor3f(r, g, b);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.75, -0.75);
    glVertex2f(0.75, -0.75);
    glVertex2f(0.0, 0.75);
    glEnd();
}

void circulo(float r, float g, float b) {
    glColor3f(r, g, b);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(0.0, 0.0);
    for (int i = 0; i <= 360; i++) {
        float theta = i * 2.0 * 3.14159 / 360;
        float x = 0.75 * cos(theta);
        float y = 0.75 * sin(theta);
        glVertex2f(x, y);
    }
    glEnd();
}

void quadradoRotativo() {
    quadrado(1.0, 0.5, 0.5);
    glPushMatrix();
    glTranslatef(-3.0, 0.0, 0.0);
    glRotatef(anguloRotacao, 0.0, 0.0, 1.0);
    quadrado(1.0, 0.5, 0.5);
    glPopMatrix();
}

void trianguloEscala() {
    triangulo(0.5, 0.5, 1.0);
    glPushMatrix();
    glTranslatef(0.0, 0.0, 0.0);
    glScalef(fatorEscala, fatorEscala, 1.0);
    triangulo(0.5, 0.5, 1.0);
    glPopMatrix();
}

void circuloTranslacaoEscala() {
    circulo(1.0, 1.0, 0.5);
    glPushMatrix();
    glTranslatef(3.0 + translacaoX, 0.0, 0.0);
    glScalef(fatorEscala, fatorEscala, 1.0);
    circulo(1.0, 1.0, 0.5);
    glPopMatrix();
}

void quadradoRefletido() {
    quadrado(0.5, 0.5, 0.5);
    glPushMatrix();
    glTranslatef(6.0, 0.0, 0.0);
    glScalef(1.0, -1.0, 1.0);
    quadrado(0.5, 0.5, 0.5);
    glPopMatrix();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    quadradoRotativo();
    trianguloEscala();
    circuloTranslacaoEscala();
    quadradoRefletido();

    glutSwapBuffers();
}

void update(int value) {
    anguloRotacao += 1.0;
    fatorEscala = 1.0 + 0.5 * sin(anguloRotacao * 3.14159 / 180.0);
    translacaoX += 0.02;

    glutPostRedisplay();
    glutTimerFunc(16, update, 0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 400);
    glutCreateWindow("Transformações Animadas");

    inicializa();

    glutDisplayFunc(display);
    glutTimerFunc(0, update, 0);
    glutMainLoop();

    return 0;
}
