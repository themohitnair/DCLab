#include <omp.h>
#include <stdio.h>

int main() {
  int iam,np;
#pragma omp parallel default(shared) private(iam, np)
  {
    int np = omp_get_num_threads();
    int iam = omp_get_thread_num();
    printf("hello from thread %d out of %d\n", iam, np);
  }
}
