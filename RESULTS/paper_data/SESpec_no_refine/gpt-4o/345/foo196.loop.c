
/*@
  logic integer sum_of_even_divisors(int n, integer limit) =
    (limit <= 1) ? 0 :
    ((n % limit == 0 && limit % 2 == 0) ? limit : 0) + sum_of_even_divisors(n, limit - 1);
*/

/*@
  logic integer sum_of_even_divisors_upto(int n, integer i) =
    sum_of_even_divisors(n, i);
*/

int foo196(int n) {

    int sum = 0;

    /*@
      loop invariant n == \at(n, Pre);
      loop assigns i, sum;
    */
    for (int i = 2; i <= n; i++) {
        if (n % i == 0) {
            if (i % 2 == 0) {
                sum += i;
            }
        }
    }

    return sum;
}
