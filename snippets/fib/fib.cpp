#include <iomanip>
#include <iostream>

using namespace std;
typedef unsigned long long BigInt;  // alias for BigInteger

BigInt get_posValueRecursive(int, BigInt, BigInt);
BigInt get_posValueFor(int);

/*
 * The Main entry point
 */
int main(int argc, char *argv[], char *env[]) {

  /*
   * Input: 0 1 2 3 4 5 6 7 8
   */
  cout << "inp: ";
  for (int i = 1; i < argc; ++i) {
    cout << setw(5) << argv[i];
  }

  cout << endl << "out: ";
  for (int i = 1; i < argc; ++i) {
    int n = strtoull(argv[i], NULL, 10);
    cout << setw(5) << get_posValueRecursive(n, 0, 1);
  }

  return 0;
}

/*
 FORMULA:
 -----------------------------------------------------------------------------
     Mathematical Induction:
         The Base Cases:
             N_0 = 0
             N_1 = 1

         Otherwise:
             value_at(N) = value_at(N-1) + value_at(N-2)

     Example:
         position N: 0  1  2  3  4  5  6
         result    : 0  1  1  2  3  5  8
*/

/*
 IMPLEMENTATION: RECURSIVE
 -----------------------------------------------------------------------------
 Given a position n (integer), return the value at that position in the
 Fibonacci sequence.

 example:
     n = 0:
        stack 0: return 0

     n = 1:
        stack 1: get_posValue(1 -1, 1, 0 + 1)
        stack 0: return 1

     n = 2:
        stack 2: get_posValue(2 -1, 1, 0 + 1)
        stack 1: get_posValue(1 -1, 1, 1 + 1)
        stack 0: return 1

      n = 3:
        stack 3: get_posValue(3 -1, 1, 0 + 1)
        stack 2: get_posValue(2 -1, 1, 1 + 1)
        stack 1: get_posValue(1 -1, 2, 1 + 2)
        stack 0: return 2

      n = 4:
        stack 4: get_posValue(4 -1, 1, 0 + 1)
        stack 3: get_posValue(3 -1, 1, 1 + 1)
        stack 2: get_posValue(2 -1, 2, 1 + 2)
        stack 1: get_posValue(1 -1, 3, 2 + 3)
        stack 0: return 3

      n = 5:
        stack 5: get_posValue(5 -1, 1, 0 + 1)
        stack 4: get_posValue(4 -1, 1, 1 + 1)
        stack 3: get_posValue(3 -1, 2, 1 + 2)
        stack 2: get_posValue(2 -1, 3, 2 + 3)
        stack 1: get_posValue(1 -1, 5, 3 + 5)
        stack 0: return 5

      n = 6:
        stack 6: get_posValue(6 -1, 1, 0 + 1)
        stack 5: get_posValue(5 -1, 1, 1 + 1)
        stack 4: get_posValue(4 -1, 2, 1 + 2)
        stack 3: get_posValue(3 -1, 3, 2 + 3)
        stack 2: get_posValue(2 -1, 5, 3 + 5)
        stack 1: get_posValue(1 -1, 8, 5 + 8)
        stack 0: return 8
*/
BigInt get_posValueRecursive(int n, BigInt curr, BigInt next) {
  if (n == 0) {
    return curr;
  }
  return get_posValueRecursive(n - 1, next, curr + next);
}

/*
    IMPLEMENTATION: ITERATIVE (FOR LOOP)
*/
BigInt get_posValueFor(int n) {
  BigInt result  = 0;
  BigInt current = 0;
  BigInt next    = 1;

  for (int i = 0; i <= n; ++i) {
    result  = current;
    current = next;
    next    = result + current;
  }

  return result;
}
