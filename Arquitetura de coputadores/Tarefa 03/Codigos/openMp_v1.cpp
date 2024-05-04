#include <iostream>
#include <vector>
#include <ctime>
#include <omp.h>

using namespace std;

void multiplicarMatrizes(const vector<vector<int>>& matriz_a, const vector<vector<int>>& matriz_b, vector<vector<int>>& matriz_resultante) {
    int tamanho_matriz = matriz_a.size();

    #pragma omp parallel for collapse(2)
    for (int i = 0; i < tamanho_matriz; ++i) {
        for (int j = 0; j < tamanho_matriz; ++j) {
            matriz_resultante[i][j] = 0;
            for (int k = 0; k < tamanho_matriz; ++k) {
                matriz_resultante[i][j] += matriz_a[i][k] * matriz_b[k][j];
            }
        }
    }
}

int main() {
    const int tamanho_max_matriz = 1000;
    const int incremento = 200;
    const int max_threads = 8;

    for (int tamanho_matriz = 200; tamanho_matriz <= tamanho_max_matriz; tamanho_matriz += incremento) {
        cout << "Tamanho da Matriz: " << tamanho_matriz << endl;

        vector<vector<int>> matriz_a(tamanho_matriz, vector<int>(tamanho_matriz, 1));
        vector<vector<int>> matriz_b(tamanho_matriz, vector<int>(tamanho_matriz, 1));
        vector<vector<int>> matriz_resultante(tamanho_matriz, vector<int>(tamanho_matriz, 0));



        // Execuntado o algoritimo em diferentes quantidades de threads
        for (int num_threads = 1; num_threads <= max_threads; num_threads *= 2) {
            omp_set_num_threads(num_threads);
            double start_time = omp_get_wtime();

            // Multiplicação das matrizes
            multiplicarMatrizes(matriz_a, matriz_b, matriz_resultante);

            double end_time = omp_get_wtime();
            double tempo_decorrido = (end_time - start_time) * 1000.0; // Convertendo para ms

            cout << "Tempo para " << num_threads << " threads: " << tempo_decorrido << " ms" << endl;
        }

        cout << "-------------------------" << endl;
    }

    return 0;
}
