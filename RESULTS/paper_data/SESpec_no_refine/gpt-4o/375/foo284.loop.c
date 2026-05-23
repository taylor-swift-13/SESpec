
/*@
  logic integer factorial(integer n) = 
    (n <= 1) ? 1 : n * factorial(n - 1);

  logic integer combination(integer n, integer r) = 
    (r == 0 || r == n) ? 1 : factorial(n) / (factorial(r) * factorial(n - r));
*/

int foo284(int num, int p) {

    if (p > num - p)
        p = num - p;
    int b = 1;

    /*@
      loop invariant num == \at(num,Pre);
      loop assigns r, b;
    */
    for (int r = 1; r <= p; r++) {
        b = b * (num - r + 1) / r;
    }

    return b;
}
