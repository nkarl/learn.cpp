#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 4

typedef struct {
    double calo; double dist; int fl; int st;
} BigData;

int compute(BigData* data, double* calo, double* dist, int* fl, int* st) {
    for (int i=0; i<TABLE_SIZE; ++i) {
        *calo += data[i].calo; *dist += data[i].dist; *fl += data[i].fl; *st += data[i].st;
    }
    return 1;
}

int main() {
    BigData *data = (BigData*)malloc(TABLE_SIZE * sizeof(BigData));
    for (int i=0; i<TABLE_SIZE; ++i) {
        data[i].calo=10; data[i].dist=10; data[i].fl=2; data[i].st=200;
    }

    double calo=0, dist=0; int fl=0, st=0;

    compute(data, &calo, &dist, &fl, &st);
    printf("calo:%f\ndist:%f\nfl:%d\nst:%d",  calo, dist, fl, st);

    return 0;
}

