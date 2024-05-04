#ifdef __APPLE__
#include <GLUT/glut.h> // Inclui a biblioteca GLUT para ambiente macOS
#else
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h> // Inclui a biblioteca GLUT para ambientes não-macOS
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
    glBegin(GL_QUADS); // Começa a definição de um quadrado
    glVertex2f(-0.75, -0.75);
    glVertex2f(-0.75, 0.75);
    glVertex2f(0.75, 0.75);
    glVertex2f(0.75, -0.75);
    glEnd(); // Finaliza a definição do quadrado
}

void drawTriangle(float r, float g, float b) {
    glColor3f(r, g, b); // Configura a cor para o triângulo
    glBegin(GL_TRIANGLES); // Começa a definição de um triângulo
    glVertex2f(-0.75, -0.75);
    glVertex2f(0.75, -0.75);
    glVertex2f(0.0, 0.75);
    glEnd(); // Finaliza a definição do triângulo
}

void drawCircle(float r, float g, float b) {
    glColor3f(r, g, b); // Configura a cor para o círculo
    glBegin(GL_TRIANGLE_FAN); // Começa a definição de um círculo
    glVertex2f(0.0, 0.0);
    for (int i = 0; i <= 360; i++) {
        float theta = i * 2.0 * 3.14159 / 360;
        float x = 0.75 * cos(theta);
        float y = 0.75 * sin(theta);
        glVertex2f(x, y);
    }
    glEnd(); // Finaliza a definição do círculo
}

void drawRotatingSquare() {
    drawSquare(1.0, 0.5, 0.5); // Desenha um quadrado vermelho claro
    glPushMatrix(); // Salva a matriz de transformação atual
    glTranslatef(-3.0, 0.0, 0.0); // Translação para a posição correta
    glRotatef(rotationAngle, 0.0, 0.0, 1.0); // Rotação em torno do eixo Z
    drawSquare(1.0, 0.5, 0.5); // Desenha o quadrado novamente (rotacionado)
    glPopMatrix(); // Restaura a matriz de transformação
}

void drawScalingTriangle() {
    drawTriangle(0.5, 0.5, 1.0); // Desenha um triângulo azul claro
    glPushMatrix(); // Salva a matriz de transformação atual
    glTranslatef(0.0, 0.0, 0.0); // Translação para a posição correta
    glScalef(scalingFactor, scalingFactor, 1.0); // Escala nos eixos X e Y
    drawTriangle(0.5, 0.5, 1.0); // Desenha o triângulo novamente (escalado)
    glPopMatrix(); // Restaura a matriz de transformação
}

void drawTranslatingScalingCircle() {
    drawCircle(1.0, 1.0, 0.5); // Desenha um círculo amarelo claro
    glPushMatrix(); // Salva a matriz de transformação atual
    glTranslatef(3.0 + translationX, 0.0, 0.0); // Translação para a posição correta
    glScalef(scalingFactor, scalingFactor, 1.0); // Escala nos eixos X e Y
    drawCircle(1.0, 1.0, 0.5); // Desenha o círculo novamente (transladado e escalado)
    glPopMatrix(); // Restaura a matriz de transformação
}

void drawReflectingSquare() {
    drawSquare(0.5, 0.5, 0.5); // Desenha um quadrado cinza
    glPushMatrix(); // Salva a matriz de transformação atual
    glTranslatef(6.0, 0.0, 0.0); // Translação para a posição correta
    glScalef(1.0, -1.0, 1.0); // Reflexão no eixo Y
    drawSquare(0.5, 0.5, 0.5); // Desenha o quadrado novamente (refletido para baixo)
    glPopMatrix(); // Restaura a matriz de transformação
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
    rotationAngle += 1.0; // Incrementa o ângulo de rotação
    scalingFactor = 1.0 + 0.5 * sin(rotationAngle * 3.14159 / 180.0); // Atualiza o fator de escala
    translationX += 0.02; // Incrementa a translação

    glutPostRedisplay(); // Solicita a redisplay da cena
    glutTimerFunc(16, update, 0); // Configura a próxima chamada de update (60 FPS)
}

int main(int argc, char** argv) {
    glutInit(&argc, argv); // Inicializa o GLUT
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); // Configura o modo de exibição
    glutInitWindowSize(800, 400); // Configura o tamanho da janela
    glutCreateWindow("Transformações Animadas"); // Cria a janela com o título especificado

    init(); // Inicializa as configurações do OpenGL

    glutDisplayFunc(display); // Define a função de exibição
    glutTimerFunc(0, update, 0); // Configura a função de update
    glutMainLoop(); // Inicia o loop principal do GLUT

    return 0; // Retorna 0 para indicar que o programa foi encerrado com sucesso
}
