
/*@ 
  logic integer div_count(integer n, integer k) =
    k <= 0 ? 0 : div_count(n, k - 1) + ((k != 0 && n % k == 0) ? 1 : 0);
*/

int foo341(int num, int z) {

    if (z < 0) {
        z = -z;
    }
    int result = 0;

    /*@
      loop invariant 1 <= loop <= z + 1;
      loop invariant num == \at(num,Pre);
      loop invariant result == div_count(num, loop - 1);
      loop assigns loop, result;
    */
    for (int loop = 1; loop <= z; loop++) {
        if (num % loop == 0) {
            result = result + 1;
        }
    }

    return result;
}
