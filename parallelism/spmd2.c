#include <omp.h>
#include <stdio.h>

/*global vars */
static long NUM_STEPS = 100000;
double step;
#define NUM_THREADS 2

void main() {
  int i;
  double x, pi, sum = 0.0;
  step = 1.0 / (double)NUM_STEPS;

  /*Create a new team of worker threads */
#pragma omp parallel for private(x) reduction(+ : sum)
  for (i = 0; i < NUM_STEPS; i++) {
    x = (i + 0.5) * step;
    sum = sum + 4.0 / (1.0 + x * x);
  } // This is a common trick in SPMD programs to create  a cyclic
    // distribution of loop iterations.
  pi += step * sum;

  printf("\nresult:\npi=%f\n", pi);
}
