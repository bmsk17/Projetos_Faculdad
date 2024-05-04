#include <iostream>
#include <vector>
#include <thread>
#include <chrono>

void multiplicarMatrizes(const std::vector<std::vector<int>>& A, const std::vector<std::vector<int>>& B,
                          std::vector<std::vector<int>>& resultado, int inicioLinha, int fimLinha) {
    for (int i = inicioLinha; i < fimLinha; ++i) {
        for (int j = 0; j < B[0].size(); ++j) {
            resultado[i][j] = 0;
            for (int k = 0; k < A[0].size(); ++k) {
                resultado[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void multiplicacaoMatrizParalela(const std::vector<std::vector<int>>& A,
                                  const std::vector<std::vector<int>>& B,
                                  std::vector<std::vector<int>>& resultado, int numThreads) {
    int numLinhasA = A.size();
    int numLinhasResultado = resultado.size();
    int linhasPorThread = numLinhasResultado / numThreads;

    std::vector<std::thread> threads;
    for (int i = 0; i < numThreads; ++i) {
        int inicioLinha = i * linhasPorThread;
        int fimLinha = (i == numThreads - 1) ? numLinhasResultado : inicioLinha + linhasPorThread;
        threads.emplace_back(multiplicarMatrizes, std::ref(A), std::ref(B), std::ref(resultado), inicioLinha, fimLinha);
    }

    for (auto& thread : threads) {
        thread.join();
    }
}

int main() {
    // Tamanhos das matrizes
    int tamanhoInicial = 5000;
    int tamanhoIncremento = 1;
    int tamanhoMaximo = 5000;
    int incrementoThreads = 2;

    for (int tamanho = tamanhoInicial; tamanho <= tamanhoMaximo; tamanho += tamanhoIncremento) {
        // Criar matrizes A, B e resultado com o tamanho atual
        std::vector<std::vector<int>> A(tamanho, std::vector<int>(tamanho, 1));
        std::vector<std::vector<int>> B(tamanho, std::vector<int>(tamanho, 1));
        std::vector<std::vector<int>> resultado(tamanho, std::vector<int>(tamanho, 0));

        std::cout << "Tamanho da Matriz: " << tamanho << " x " << tamanho << std::endl;

        // Execuntado o algoritimo em diferentes quantidades de threads
        for (int numThreads = 1; numThreads <= std::thread::hardware_concurrency(); numThreads *= incrementoThreads) {
            auto inicio = std::chrono::high_resolution_clock::now();

            // Multiplicação das matrizes
            multiplicacaoMatrizParalela(A, B, resultado, numThreads);

            auto fim = std::chrono::high_resolution_clock::now();
            auto duracao = std::chrono::duration_cast<std::chrono::milliseconds>(fim - inicio).count();

            std::cout << "threads: " << numThreads << ", tempo de execucao: " << duracao << " ms" << std::endl;
        }

        std::cout << std::endl;
    }

    return 0;
}
