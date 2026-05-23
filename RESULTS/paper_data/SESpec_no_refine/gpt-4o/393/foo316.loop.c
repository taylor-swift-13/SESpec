
/*@
  logic integer factorial(integer n) =
    n <= 1 ? 1 : n * factorial(n - 1);
*/

/*@
  requires num >= 0;
  ensures \result == (factorial(num) % 100);
*/
int foo316(int num) {

    int ret = 1;

    /*@
      loop invariant 1 <= loop <= \at(num,Pre) + 1;
      loop invariant ret == factorial(loop - 1);
      loop invariant num == \at(num,Pre);
      loop assigns loop, ret;
    */
    for (int loop = 1; loop <= num; loop++) {
        ret *= loop;
    }

    int remainder = (int) (ret % 100);
    return remainder;
}
