#include <stdint.h>
#include <stdio.h>
#include <time.h>

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

double get_execution_time(struct timespec start_time, struct timespec end_time) {
    time_t sec_diff = end_time.tv_sec - start_time.tv_sec;
    long nsec_diff = end_time.tv_nsec - start_time.tv_nsec;

    double total_time = (double)sec_diff + (double)nsec_diff / 1e9;
    return total_time;
}

int main() {
    uint32_t seed = 0; // Defina o valor inicial desejado
    uint32_t length = 1000000; // Defina a quantidade de números aleatórios a serem gerados

    uint32_t sequence[length];

    struct timespec start_time, end_time;

    clock_gettime(CLOCK_MONOTONIC, &start_time); // Marca o tempo de início

    mlcg_generate_sequence(sequence, length, seed);

    clock_gettime(CLOCK_MONOTONIC, &end_time); // Marca o tempo de término

    double execution_time = get_execution_time(start_time, end_time);

    printf("Tempo de execução: %.12f segundos\n", execution_time);

    return 0;
}
