
/*@
  logic integer factorial(integer n) =
    n <= 1 ? 1 : n * factorial(n - 1);
*/

/*@
  requires num >= 0 && num <= 12; // Restrict num to prevent overflow
  assigns \nothing;
  ensures \result == factorial(num) % 100;
  ensures num >= 0;
  ensures \result >= 0 && \result < 100;
*/
int foo393(int num) {

    int ret = 1;

    /*@
      loop invariant 1 <= loop <= num + 1;
      loop invariant ret == factorial(loop - 1);
      loop invariant num >= 0;
      loop invariant num == \at(num, Pre);
      loop invariant (loop <= num) ==> (ret == factorial(loop - 1));
      loop invariant (!(loop <= num)) ==> ((ret == factorial(num)) && (num == \at(num, Pre)));
      loop assigns loop, ret;
    */
    for (int loop = 1; loop <= num; loop++) {
        ret *= loop;
    }

    int remainder = (int) (ret % 100);

    /*@
      assert remainder == factorial(num) % 100;
    */
    return remainder;
}
