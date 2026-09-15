
/*@ 
  logic integer factorial(integer n) = 
    (n == 0) ? 1 : n * factorial(n - 1);
*/

/*@
  requires num >= 0;
  assigns \nothing;
  ensures \result == factorial(num) % 100;
*/
int foo317(int num) {

    int ret = 1;

    /*@
      loop invariant 1 <= loop <= num + 1;
      loop invariant ret == factorial(loop - 1);
      loop invariant num == \at(num, Pre);
      loop assigns loop, ret;
    */
    for (int loop = 1; loop <= num; loop++) {
        ret *= loop;
    }

    int result = (int) (ret % 100);
    return result;
}
