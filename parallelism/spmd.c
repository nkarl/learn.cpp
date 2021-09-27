#include <omp.h>
#include <stdio.h>

static long NUM_STEPS = 100000;

#define NUM_THREADS 2

void main() {
    int i, nTHREADs;
    double pi, sum[NUM_THREADS];
    double step = 1.0/(double) NUM_STEPS;

    omp_set_num_threads(NUM_THREADS);

# pragma omp parallel
    {
        int i, id, nTHRDs;
        double x;
        
        id = omp_get_thread_num();

        nTHRDs = omp_get_num_threads();

        if (id == 0) nTHREADs = nTHRDs;
        for (i=id, sum[id]=0.0; i<NUM_STEPS; i=i+nTHRDs) {
            x = (i+0.5)*step;

            sum[id] += 4.0/(1.0+x*x);
        }
    }

    for (i=0, pi=0.0; i<nTHREADs; i++)
        pi += sum[i] * step;

    printf("%f\n", pi);
}
