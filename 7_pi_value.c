#include <stdio.h>
#include <omp.h>

int main() {
    int n = 100000000;
    double pi_serial = 0.0, pi_parallel = 0.0;

    double start_time = omp_get_wtime();
    for (int k = 0; k < n; k++) {
        pi_serial += ((k % 2 == 0) ? 1.0 : -1.0) / (2 * k + 1);
    }
    pi_serial *= 4;
    double serial_time = omp_get_wtime() - start_time;

    start_time = omp_get_wtime();
    #pragma omp parallel for reduction(+:pi_parallel)
    for (int k = 0; k < n; k++) {
        pi_parallel += ((k % 2 == 0) ? 1.0 : -1.0) / (2 * k + 1);
    }
    pi_parallel *= 4;
    double parallel_time = omp_get_wtime() - start_time;

    printf("Estimated value of pi (serial)   = %.15f\n", pi_serial);
    printf("Serial execution time            = %.6f seconds\n", serial_time);
    printf("Estimated value of pi (parallel) = %.15f\n", pi_parallel);
    printf("Parallel execution time          = %.6f seconds\n", parallel_time);

    return 0;
}
