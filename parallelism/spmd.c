#include <omp.h>
#include <stdio.h>

/*global vars */
static long NUM_STEPS = 100000;
double step;
#define NUM_THREADS 2

void main() {
  int i, nTHREADS_shared;
  double pi, sum[NUM_THREADS]; // promote scalar to an array dimensioned by
                               // number of threads to avoid race condition.

  step = 1.0 / (double)NUM_STEPS;
  printf("step=%f\n", step);

  omp_set_num_threads(NUM_THREADS); // set the number of threads =2

  /*Create a new team of worker threads */
#pragma omp parallel
  {
    /*local vars, local to each thread */
    int i, id, nTHREADS;
    double x;

    id = omp_get_thread_num();        // get the id of the executing thread
    nTHREADS = omp_get_num_threads(); // assign the num_threads to the local var

    if (id == 0) {
      nTHREADS_shared = nTHREADS;
    } // only one thread should copy tyhe
      // num_threads to the shared value to make sure multiple
      // threads writing to the same address don't conflict.

    for (i = id, sum[id] = 0.0; i < NUM_STEPS; i = i + nTHREADS) {
      x = (i + 0.5) * step;
      sum[id] += 4.0 / (1.0 + x * x);
    } // This is a common trick in SPMD programs to create  a cyclic
      // distribution of loop iterations.
  }

  for (i = 0, pi = 0.0; i < nTHREADS_shared; i++)
    pi += sum[i] * step;

  printf("\nresult:\npi=%f\n", pi);
}
