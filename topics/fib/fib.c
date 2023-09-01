#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long BigInt;

///
/// Given a position n (integer), return the value at that position in the Fibonacci sequence.
///
/// example:
///     n = 0, 0, 1: return 0
///     n = 1, 0, 1:
///         stack 1: get_posValue(1 -1, 1, 0 + 1)
///         stack 0: return 1
///     n = 2, 0, 1: 
///         stack 2: get_posValue(2 -1, 1, 0 + 1)
//          stack 1: get_posValue(1 -1, 1, 1 + 1)
//          stack 0: return 1
//      n = 3, 0, 1:
///         stack 3: get_posValue(3 -1, 1, 0 + 1)
//          stack 2: get_posValue(2 -1, 1, 1 + 1)
//          stack 1: get_posValue(1 -1, 2, 1 + 2)
//          stack 0: return 2
//      n = 4, 0, 1:
///         stack 4: get_posValue(4 -1, 1, 0 + 1)
//          stack 3: get_posValue(3 -1, 1, 1 + 1)
//          stack 2: get_posValue(2 -1, 2, 1 + 2)
//          stack 1: get_posValue(1 -1, 3, 2 + 3)
//          stack 0: return 3
//      n = 5, 0, 1:
///         stack 5: get_posValue(5 -1, 1, 0 + 1)
//          stack 4: get_posValue(4 -1, 1, 1 + 1)
//          stack 3: get_posValue(3 -1, 2, 1 + 2)
//          stack 2: get_posValue(2 -1, 3, 2 + 3)
//          stack 1: get_posValue(1 -1, 5, 3 + 5)
//          stack 0: return 5
//      n = 6, 0, 1:
///         stack 6: get_posValue(6 -1, 1, 0 + 1)
//          stack 5: get_posValue(5 -1, 1, 1 + 1)
//          stack 4: get_posValue(4 -1, 2, 1 + 2)
//          stack 3: get_posValue(3 -1, 3, 2 + 3)
//          stack 2: get_posValue(2 -1, 5, 3 + 5)
//          stack 1: get_posValue(1 -1, 8, 5 + 8)
//          stack 0: return 8
BigInt get_posValue(int n, BigInt curr, BigInt next) {
    if (n == 0) {
        return curr;
    }
    return get_posValue(n - 1, next, curr + next);
}

BigInt get_posValueFor(int n) {
    BigInt res = 0;
    BigInt curr = 0;
    BigInt next = 1;

    for (int i=0; i<=n; ++i) {
        res = curr;
        curr = next;
        next = res + curr;
    }
    return res;
}

int main(int argc, char *argv[], char *env[]) {
    /*for (int i=0; i < argc; ++i) {*/
        /*printf("[%d]%s\n", i, argv[i]);*/
    /*}*/
    printf("inp: ");
    for (int i=1; i < argc; ++ i) {
        printf("%s  ", argv[i]);
    }
    printf("\n");
    printf("out: ");
    for (int i=1; i < argc; ++ i) {
        int n = strtoull(argv[i], NULL, 10);
        /*printf("%lld  ", get_posValue(n, 0, 1));*/
        printf("%lld  ", get_posValueFor(n));
    }
    return 0;
}
