
/*@
  logic integer count_divisors(integer n, integer z) =
    \sum(1, z, \lambda integer i; (n % i == 0 ? 1 : 0));
*/

/*@
  requires \true;
  assigns z;
  ensures z == \abs(\at(z, Pre));
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
      loop invariant z == \at(z, Pre);
      loop invariant n == \at(n, Pre);
      loop assigns loop, result;
      loop variant z - loop;
    */
    for (int loop = 1; loop <= z; loop++) {
        if (n % loop == 0) {
            result = result + 1;
        }
    }

    return result;
}
