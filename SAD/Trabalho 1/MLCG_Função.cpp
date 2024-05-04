#include <iostream>
#include <vector>

#define MLCG_M 4294967296 // 2^32
#define MLCG_A 1664525
#define MLCG_C 1013904223

void gerar_numeros_aleatorios(uint32_t seed, uint32_t length) {
    std::vector<uint32_t> sequence(length);

    uint32_t x = seed;
    for (uint32_t i = 0; i < length; i++) {
        x = (MLCG_A * x + MLCG_C) % MLCG_M;
        sequence[i] = x;
    }

    std::cout << "Números gerados:" << std::endl;
    for (uint32_t i = 0; i < length; i++) {
        std::cout << sequence[i] << std::endl;
    }
}

int main() {
    uint32_t seed = 0;
    uint32_t length = 100;

    gerar_numeros_aleatorios(seed, length);

    return 0;
}
