
/*@
  logic integer count_divisors(integer n, integer limit) =
    limit <= 0 ? 0 : (n % limit == 0 ? 1 : 0) + count_divisors(n, limit - 1);
*/

/*@
  requires \at(z,Pre) >= 0 && (z == \at(z,Pre)) && (n == \at(n,Pre)) || \at(z,Pre) < 0 && (z == -\at(z,Pre)) && (n == \at(n,Pre));
  ensures \result == count_divisors(n, z);
*/
int foo191(int n, int z) {

    if (z < 0) {
        z = -z;
    }
    int result = 0;

    /*@
      loop invariant 1 <= loop <= z + 1;
      loop invariant result == count_divisors(n, loop - 1);
      loop invariant z == \at(z,Pre);
      loop invariant n == \at(n,Pre);
      loop assigns loop, result;
    */
    for (int loop = 1; loop <= z; loop++) {
        if (n % loop == 0) {
            result = result + 1;
        }
    }

    return result;
}
