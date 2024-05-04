#ifdef __APPLE__
#include <GLUT/glut.h> // Inclui a biblioteca GLUT para ambiente macOS
#else
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h> // Inclui a biblioteca GLUT para ambientes n�o-macOS
#endif

#include <GL/glut.h>
#include <cmath>

float translationX = 0.0;
float scalingFactor = 1.0;
float rotationAngle = 0.0;

void init() {
    glClearColor(1.0, 1.0, 1.0, 1.0); // Configura a cor de fundo como branco
    gluOrtho2D(-7.0, 7.0, -5.0, 5.0); // Configura o sistema de coordenadas
}

void drawSquare(float r, float g, float b) {
    glColor3f(r, g, b); // Configura a cor para o quadrado
    glBegin(GL_QUADS); // Come�a a defini��o de um quadrado
    glVertex2f(-0.75, -0.75);
    glVertex2f(-0.75, 0.75);
    glVertex2f(0.75, 0.75);
    glVertex2f(0.75, -0.75);
    glEnd(); // Finaliza a defini��o do quadrado
}

void drawTriangle(float r, float g, float b) {
    glColor3f(r, g, b); // Configura a cor para o tri�ngulo
    glBegin(GL_TRIANGLES); // Come�a a defini��o de um tri�ngulo
    glVertex2f(-0.75, -0.75);
    glVertex2f(0.75, -0.75);
    glVertex2f(0.0, 0.75);
    glEnd(); // Finaliza a defini��o do tri�ngulo
}

void drawCircle(float r, float g, float b) {
    glColor3f(r, g, b); // Configura a cor para o c�rculo
    glBegin(GL_TRIANGLE_FAN); // Come�a a defini��o de um c�rculo
    glVertex2f(0.0, 0.0);
    for (int i = 0; i <= 360; i++) {
        float theta = i * 2.0 * 3.14159 / 360;
        float x = 0.75 * cos(theta);
        float y = 0.75 * sin(theta);
        glVertex2f(x, y);
    }
    glEnd(); // Finaliza a defini��o do c�rculo
}

void drawRotatingSquare() {
    drawSquare(1.0, 0.5, 0.5); // Desenha um quadrado vermelho claro
    glPushMatrix(); // Salva a matriz de transforma��o atual
    glTranslatef(-3.0, 0.0, 0.0); // Transla��o para a posi��o correta
    glRotatef(rotationAngle, 0.0, 0.0, 1.0); // Rota��o em torno do eixo Z
    drawSquare(1.0, 0.5, 0.5); // Desenha o quadrado novamente (rotacionado)
    glPopMatrix(); // Restaura a matriz de transforma��o
}

void drawScalingTriangle() {
    drawTriangle(0.5, 0.5, 1.0); // Desenha um tri�ngulo azul claro
    glPushMatrix(); // Salva a matriz de transforma��o atual
    glTranslatef(0.0, 0.0, 0.0); // Transla��o para a posi��o correta
    glScalef(scalingFactor, scalingFactor, 1.0); // Escala nos eixos X e Y
    drawTriangle(0.5, 0.5, 1.0); // Desenha o tri�ngulo novamente (escalado)
    glPopMatrix(); // Restaura a matriz de transforma��o
}

void drawTranslatingScalingCircle() {
    drawCircle(1.0, 1.0, 0.5); // Desenha um c�rculo amarelo claro
    glPushMatrix(); // Salva a matriz de transforma��o atual
    glTranslatef(3.0 + translationX, 0.0, 0.0); // Transla��o para a posi��o correta
    glScalef(scalingFactor, scalingFactor, 1.0); // Escala nos eixos X e Y
    drawCircle(1.0, 1.0, 0.5); // Desenha o c�rculo novamente (transladado e escalado)
    glPopMatrix(); // Restaura a matriz de transforma��o
}

void drawReflectingSquare() {
    drawSquare(0.5, 0.5, 0.5); // Desenha um quadrado cinza
    glPushMatrix(); // Salva a matriz de transforma��o atual
    glTranslatef(6.0, 0.0, 0.0); // Transla��o para a posi��o correta
    glScalef(1.0, -1.0, 1.0); // Reflex�o no eixo Y
    drawSquare(0.5, 0.5, 0.5); // Desenha o quadrado novamente (refletido para baixo)
    glPopMatrix(); // Restaura a matriz de transforma��o
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT); // Limpa o buffer de cor

    drawRotatingSquare();
    drawScalingTriangle();
    drawTranslatingScalingCircle();
    drawReflectingSquare();

    glutSwapBuffers(); // Troca os buffers para exibir o desenho
}

void update(int value) {
    rotationAngle += 1.0; // Incrementa o �ngulo de rota��o
    scalingFactor = 1.0 + 0.5 * sin(rotationAngle * 3.14159 / 180.0); // Atualiza o fator de escala
    translationX += 0.02; // Incrementa a transla��o

    glutPostRedisplay(); // Solicita a redisplay da cena
    glutTimerFunc(16, update, 0); // Configura a pr�xima chamada de update (60 FPS)
}

int main(int argc, char** argv) {
    glutInit(&argc, argv); // Inicializa o GLUT
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); // Configura o modo de exibi��o
    glutInitWindowSize(800, 400); // Configura o tamanho da janela
    glutCreateWindow("Transforma��es Animadas"); // Cria a janela com o t�tulo especificado

    init(); // Inicializa as configura��es do OpenGL

    glutDisplayFunc(display); // Define a fun��o de exibi��o
    glutTimerFunc(0, update, 0); // Configura a fun��o de update
    glutMainLoop(); // Inicia o loop principal do GLUT

    return 0; // Retorna 0 para indicar que o programa foi encerrado com sucesso
}
