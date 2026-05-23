
#include <stdlib.h>

/*@
  requires n >= 0;
  ensures \result >= -1;
*/
int foo105(int n) {

    if(n < 0) return -1;
    else if(n == 0) return 0;

    int *fib = (int *)malloc(sizeof(int) * (n + 1));
    int fib_len = n + 1;
    fib[0] = 0;
    fib[1] = 1;
    int index = 2;

    /*@
      loop invariant 2 <= index <= fib_len;
      loop invariant fib_len == n + 1;
      loop invariant fib[0] == 0;
      loop invariant fib[1] == 1;
      loop invariant \forall integer k; 2 <= k < index ==> fib[k] == fib[k-1] + fib[k-2];
      loop invariant \forall integer k; 0 <= k < index ==> fib[k] >= 0;
      loop invariant \forall integer k; 1 <= k < index ==> fib[k] >= fib[k-1];
      loop invariant (index < fib_len) ==> (fib[index - 2] >= 0 && fib[index - 1] >= 0);
      loop invariant (!(index < fib_len)) ==> (index == fib_len);
      loop assigns fib[0..fib_len-1], index;
    */
    while (index < fib_len) {
        fib[index] = fib[index - 2] + fib[index - 1];
        index++;
    }

    return fib[n];
}
