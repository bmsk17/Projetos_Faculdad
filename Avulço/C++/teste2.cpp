#include <stdint.h>

uint64_t xorshift64(uint64_t* state) {
    uint64_t x = *state;
    x ^= x << 13;
    x ^= x >> 7;
    x ^= x << 17;
    *state = x;
    return x;
}

int main() {
    uint64_t state = /* valor inicial do estado */;

    // Gerar alguns números aleatórios
    for (int i = 0; i < 10; i++) {
        uint64_t random_number = xorshift64(&state);
        printf("%lu\n", random_number);
    }

    return 0;
}
