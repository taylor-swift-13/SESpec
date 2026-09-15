
        /*@
logic integer count_divisors_up_to(integer n, integer k) =
  k <= 0 ? 0 : count_divisors_up_to(n, k - 1) + (n % k == 0 ? 1 : 0);
*/
/*@
assigns \nothing;
ensures \result == count_divisors_up_to(num, num);
ensures \result >= 0;
ensures num > 0 ==> \result >= 1;
*/
int foo372(int num) {
  int div = 0;

  /*@
    loop invariant 1 <= c;
    loop invariant c == 1 || c <= num + 1;
    loop invariant div == count_divisors_up_to(num, c - 1);
    loop invariant num <= 0 || div >= 1 || c == 1;
    loop assigns c, div;
    loop variant num < c ? 0 : num - c + 1;
  */
  for (int c = 1; c <= num; c++) {
    if (num % c == 0) {
      div++;
    }
  }

  return div;
}
