#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define MLCG_M 4294967296 // 2^32
#define MLCG_A 1664525
#define MLCG_C 1013904223

void mlcg_generate_sequence(uint32_t *sequence, uint32_t length, uint32_t seed) {
    uint32_t x = seed;

    for (uint32_t i = 0; i < length; i++) {
        x = (MLCG_A * x + MLCG_C) % MLCG_M;
        sequence[i] = x;
    }
}

int main() {
    uint32_t seed = 0;
    uint32_t length = 100;

    uint32_t *sequence = malloc(length * sizeof(uint32_t));
    if (sequence == NULL) {
        printf("Erro ao alocar memória.\n");
        return 1;
    }

    mlcg_generate_sequence(sequence, length, seed);

    printf("Números gerados:\n");
    for (uint32_t i = 0; i < length; i++) {
        printf("%u\n", sequence[i]);
    }

    free(sequence);

    return 0;
}
