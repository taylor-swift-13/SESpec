
/*@
  logic integer fib(integer n) =
    n == 0 ? 0
    : n == 1 ? 1
    : fib(n-1) + fib(n-2);
*/

int foo296(int seed) {

    int *result = (int *)malloc(sizeof(int) * (seed + 1));
    int result_len = seed + 1;
    result[0] = 2;
    result[1] = 1;

    /*@ assert \valid(result + (0 .. seed)); */
    
    /*@
      loop invariant 2 <= c;
      loop invariant \valid(result + (0 .. seed));
                          result[k] == result[k-1] + result[k-2];
      loop assigns c, result[0 .. seed];
    */
    for (int c = 2; c <= seed; c++) {
        result[c] = result[c - 1] + result[c - 2];
    }
    
    return result[seed];
}
