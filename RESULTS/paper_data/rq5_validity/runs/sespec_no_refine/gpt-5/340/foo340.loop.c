
/*@
  logic integer count_divisors_up_to(integer n, integer b) =
    (b <= 0) ? 0 :
    count_divisors_up_to(n, b - 1) + ((n % b == 0) ? 1 : 0);
*/

int foo340(int n, int z) {

    if (z < 0) {
        z = -z;
    }
    int result = 0;

    /*@ 
      loop invariant 1 <= loop <= z + 1;
      loop invariant z >= 0;
      loop invariant result == count_divisors_up_to(n, loop - 1);
      loop assigns loop, result;
    */
    for (int loop = 1; loop <= z; loop++) {
        if (n % loop == 0) {
            result = result + 1;
        }
    }

    return result;
}
