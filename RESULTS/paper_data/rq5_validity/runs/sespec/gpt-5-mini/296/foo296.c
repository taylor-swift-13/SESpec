
/*@ 
  logic integer fib_shift(integer n) =
    n == 0 ? 2
    : n == 1 ? 1
    : fib_shift(n-1) + fib_shift(n-2);
*/

/*@
  // A simple contract for malloc to help verification: when n>0 it returns
  // a non-null pointer and a valid block of n elements of type char.
  // Placed in the file so calls to malloc can be reasoned about.
  requires n > 0;
  assigns \result;
  ensures \result != \null;
  ensures \valid((char*)\result + (0 .. n-1));
*/
void *malloc(unsigned long n);

/*@
  requires seed >= 1;
  assigns \nothing;
*/
int foo296(int seed) {

    int *result = (int *)malloc(sizeof(int) * (seed + 1));
    int result_len = seed + 1;
    result[0] = 2;
    result[1] = 1;

    /*@ assert result != \null && \valid((int*)result + (0 .. seed)); */
    
    /*@
      loop invariant 2 <= c <= seed + 1;
      loop invariant \valid((int*)result + (0 .. seed));
      loop invariant result[0] == 2 && result[1] == 1;
      loop invariant \forall integer i; 2 <= i < c ==> result[i] == result[i-1] + result[i-2];
      loop assigns c, result[0 .. seed];
    */
    for (int c = 2; c <= seed; c++) {
        result[c] = result[c - 1] + result[c - 2];
    }
    
    return result[seed];
}
