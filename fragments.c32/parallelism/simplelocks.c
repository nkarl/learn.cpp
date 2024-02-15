#include <omp.h>
#include <stdio.h>

void main() {
    int id;
#pragma omp parallel private(id)
    {
        id = omp_get_thread_num();
#pragma omp critical
        {
            printf("%d\n", id);
        }
    }
}
