#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

#define MLCG_M 4294967296 // 2^32
#define MLCG_A 1664525
#define MLCG_C 1013904223

void gerar_numeros_aleatorios(uint32_t semente, uint32_t comprimento, vector<double>& numeros_aleatorios) {
    numeros_aleatorios.reserve(comprimento);

    uint32_t x = semente;
    for (uint32_t i = 0; i < comprimento; i++) {
        x = (MLCG_A * x + MLCG_C) % MLCG_M;
        numeros_aleatorios.push_back(static_cast<double>(x) / MLCG_M);
    }
}

int main() {
    uint32_t semente = 0;
    uint32_t comprimento = 2 * 10 * 20 + 10 * 20;
    vector<double> numeros_aleatorios;

    gerar_numeros_aleatorios(semente, comprimento, numeros_aleatorios);

    vector<string> estados = {"Vitoria", "Empate", "Derrota"};
    int num_estados = estados.size();

    double matriz_transicao[3][3] = {
        {0.529, 0.118, 0.353},
        {0.643, 0.214, 0.143},
        {0.357, 0.071, 0.572}
    };

    int num_simulacoes = 10;
    int num_passos = 20;

    for (int simulacao = 0; simulacao < num_simulacoes; simulacao++) {
        cout << "Simulação " << simulacao + 1 << ":\n";

        int indice_estado_inicial = numeros_aleatorios[simulacao * 2 * num_passos * 2] * num_estados;
        string estado_atual = estados[indice_estado_inicial];
        vector<string> estados_simulados = {estado_atual};

        int vitorias = 0;
        int empates = 0;
        int derrotas = 0;

        for (int passo = 0; passo < num_passos; passo++) {
            double num_aleatorio = numeros_aleatorios[simulacao * num_passos * 2 + passo + 1];
            double probabilidade_cumulativa = 0.0;
            int indice_proximo_estado = 0;

            for (int i = 0; i < num_estados; i++) {
                probabilidade_cumulativa += matriz_transicao[indice_estado_inicial][i];
                if (num_aleatorio < probabilidade_cumulativa) {
                    indice_proximo_estado = i;
                    break;
                }
            }

            string proximo_estado = estados[indice_proximo_estado];
            estados_simulados.push_back(proximo_estado);
            estado_atual = proximo_estado;

            if (proximo_estado == "Vitoria") {
                vitorias++;
            } else if (proximo_estado == "Empate") {
                empates++;
            } else if (proximo_estado == "Derrota") {
                derrotas++;
            }
        }

        int total = vitorias + empates + derrotas;
        double pct_vitorias = (static_cast<double>(vitorias) / total) * 100;
        double pct_empates = (static_cast<double>(empates) / total) * 100;
        double pct_derrotas = (static_cast<double>(derrotas) / total) * 100;

        cout << "Vitórias: " << fixed << setprecision(1) << pct_vitorias << "% | Empates: " << pct_empates << "% | Derrotas: " << pct_derrotas << "%\n";
    }

    return 0;
}
