#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main () {
    struct timespec start, end;
    double time_spent;
    int x;


    srand (time (NULL));
    clock_gettime (CLOCK_MONOTONIC, &start);

    for (int i = 0; i < 100000000; i++) {
        x = rand ();
    }

    clock_gettime (CLOCK_MONOTONIC, &end);
    time_spent = (end.tv_sec - start.tv_sec) +
     (end.tv_nsec - start.tv_nsec) / 1e9;

    printf ("%f seconds\n", time_spent);

return 0;
}
