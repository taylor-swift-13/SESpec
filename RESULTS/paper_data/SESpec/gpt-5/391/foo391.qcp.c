#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo391(int n) 
/*@

Require emp
Ensure Results(__return)
*/{

        int i = 1;
        int square = 1;
       
  /*@ Inv
    (1 <= i) &&
    (1 <= square) &&
    (n == n@pre) &&
    (i >= 1 => square >= 1) &&
    (i >= 1 => (i - 1) <= square) &&
    (i >= 1 => (i - 1) * (i - 1) <= square) &&
    (i >= 2 => (i - 2) * (i - 2) < square) &&
    (forall (k:Z), 1 <= k && k < i => (k * k) <= square) &&
    (exists (k:Z), 1 <= k && k < i => square == k * k) &&
    ((square <= n) => (i - 1) * (i - 1) <= n) &&
    ((i >= 2) => ((i - 2) * (i - 2) <= n => (i - 1) * (i - 1) <= n || square > n)) &&
    ((i >= 2) => ((i - 2) * (i - 2) <= n)) &&
    ((square >= (i - 1))) &&
    ((1 <= n@pre) => (i >= 1)) &&
    ((1 <= n@pre) => (((square == 1)&&(i == 1)&&(n == n@pre)) || (square == (i - 1) * (i - 1)))) &&
    ((!(1 <= n@pre)) => ((square == 1)&&(i == 1)&&(n == n@pre))) &&
    (n == n@pre)
    */
while (square <= n) {
            square = i*i;
            i++;
        }
        return square;
}