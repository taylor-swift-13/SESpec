
/*@
  logic integer fact_prefix(integer n) =
    (n <= 0) ? 1 : n * fact_prefix(n - 1);
*/

/*@
  requires num >= 0;
  ensures \result == (int)(((fact_prefix(num)) % 100 + 100) % 100);
*/
int foo317(int num) {

    int ret = 1;

    /*@
      loop invariant 1 <= loop <= num + 1;
      loop invariant ret == fact_prefix(loop - 1);
      loop invariant num == \at(num,Pre);
      loop assigns loop, ret;
    */
    for (int loop = 1; loop <= num; loop++) {
        ret *= loop;
    }

    int result = (int) (ret % 100);
    return result;
}
