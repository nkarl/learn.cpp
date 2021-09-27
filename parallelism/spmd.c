#include <omp.h>
#include <stdio.h>

static long NUM_STEPS = 100000;
double step;

#define NUM_THREADS 2

void main() {
  int i, nTHREADs;
  double pi, sum[NUM_THREADS];

  step = 1.0 / (double)NUM_STEPS;
  printf("step=%f\n", step);

  omp_set_num_threads(NUM_THREADS);     // set the number of threads =2

  /*Create a new team of worker threads */
#pragma omp parallel
  {
    int i, id, nTHRDs;
    double x;

    id = omp_get_thread_num();          // assign the thread# to id
    nTHRDs = omp_get_num_threads();     // assign the num_threads to the local var

    if (id == 0)
      nTHREADs = nTHRDs;

    for (i = id, sum[id] = 0.0; i < NUM_STEPS; i = i + nTHRDs) {
      x = (i + 0.5) * step;
      sum[id] += 4.0 / (1.0 + x * x);
    }
  }

  for (i = 0, pi = 0.0; i < nTHREADs; i++)
    pi += sum[i] * step;

  printf("\nresult:\npi=%f\n", pi);
}
