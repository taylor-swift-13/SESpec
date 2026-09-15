#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
int foo367(int n) 
/*@

Require emp
Ensure Results(__return)
*/{

        int i = 2;
       
  /*@ Inv
    (2 <= i) &&
    (n == n@pre) &&
    (i == 2 + (i - 2)) &&
    (forall (k:Z), 2 <= k && k < i => n % k != 0) &&
    (forall (k:Z), 2 <= k && k < i => (k == 0 || n / k < n)) &&
    (i == 2 => true) &&
    (2 <= n@pre => i <= n@pre) &&
    (i <= n@pre || i > n@pre) &&
    ((i > n@pre / i) => (forall (k:Z), 2 <= k && k < i => n % k != 0)) &&
    ((i > n@pre / i) => (i * i > n@pre)) &&
    ((2 <= n@pre / 2) => ((forall (k:Z), 2 <= k && k <= n@pre / k => n % k != 0) => false || true)) &&
    ((2 <= n@pre / 2) => (forall (k:Z), 2 <= k && k < i => k <= n@pre / k)) &&
    ((i <= n@pre / i) => (i <= n@pre)) &&
    ((i >= 3) => (i - 1 >= 2)) &&
    (exists (t:Z), t == i - 2 && t >= 0) &&
    ((i > n@pre / i) => (n == n@pre)) &&
    ((2 <= n@pre / 2) => ( (i >= 2) && (i <= n@pre) )) &&
    ((2 <= n@pre / 2) => (i >= 2)) &&
    ((!(2 <= n@pre / 2)) => ((i == 2)&&(n == n@pre))) &&
    (n == n@pre)
    */
while (i <= n / i) {
            if (n % i == 0) {
                return i;
            }
            i++;
        }
        return n;
}