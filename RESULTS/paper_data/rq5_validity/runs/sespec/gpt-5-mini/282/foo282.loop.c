
/*@
  logic integer count_divs(integer n, integer lo, integer hi) =
    lo >= hi ? 0
             : count_divs(n, lo, hi - 1) + (n % (hi - 1) == 0 ? 1 : 0);
*/

/*@
  requires num == \at(num,Pre);
*/
const char * foo282(int num) {

    int result = 0;

    /*@
      loop invariant 1 <= c;
      loop invariant 0 <= result <= c - 1;
      loop invariant result == count_divs(num, 1, c);
      loop invariant \forall integer p, q; 1 <= p <= q < c ==>
                        (count_divs(num, 1, p) <= count_divs(num, 1, q));
      loop invariant (result > 0) ==> (\exists integer k; 1 <= k < c && num % k == 0);
      loop invariant num == \at(num,Pre);
      loop assigns c, result;
    */
    for (int c = 1; c <= num; c++) {
        if (num % c == 0) {
            result++;
        }
    }

    if (result % 2 == 0) {
        return "Even";
    } else {
        return "Odd";
    }
}
