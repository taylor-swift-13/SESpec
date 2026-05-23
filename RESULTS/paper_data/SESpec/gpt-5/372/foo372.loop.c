
/*@ logic integer count_div(integer n, integer k) =
      k <= 0 ? 0 : count_div(n, k - 1) + ((n % k == 0) ? 1 : 0);
*/
int foo372(int num) {

  int div = 0;

  /* >>> LOOP INVARIANT TO FILL <<< */

  /*@
    loop invariant num == \at(num,Pre);

    loop invariant c >= 1;
    loop invariant (num >= 1) ==> (1 <= c && c <= num + 1);
    loop invariant (num < 1) ==> (c == 1);

    loop invariant div >= 0;
    loop invariant (c <= \at(num,Pre)) ==> (div <= c - 1);

    loop invariant (c <= \at(num,Pre)) ==>
      (div > 0 ==> \exists integer k; 1 <= k < c && num % k == 0);

    loop invariant (c <= \at(num,Pre)) ==>
      (\forall integer k; 1 <= k < c ==> ((num % k == 0) ==> div >= 1));

    loop invariant div == count_div(num, c - 1);
    loop assigns c, div;
  */
  for (int c = 1; c <= num; c++) {
    if (num % c == 0) {
      div++;
    }
  }

  return div;
}
