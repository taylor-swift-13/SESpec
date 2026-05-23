
/*@
  logic integer count_divisors(integer num, integer z) =
    \sum(1, z, \lambda integer i; (num % i == 0 ? 1 : 0));
*/

/*@
  requires \valid(&num) && \valid(&z);
  assigns z, \nothing;
  ensures z >= 0 ==> (\result == count_divisors(num, z));
  ensures z < 0 ==> (\result == count_divisors(num, -z));
*/
int foo192(int num, int z) {

    if (z < 0) {
        z = -z;
    }
    int result = 0;

    /*@
      loop invariant 1 <= loop <= z + 1;
      loop invariant result == count_divisors(num, loop - 1);
      loop invariant z == \at(z,Pre);
      loop invariant num == \at(num,Pre);
      loop assigns loop, result;
    */
    for (int loop = 1; loop <= z; loop++) {
        if (num % loop == 0) {
            result = result + 1;
        }
    }

    return result;
}
