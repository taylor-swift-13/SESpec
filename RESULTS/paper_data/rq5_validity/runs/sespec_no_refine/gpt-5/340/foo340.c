
/*@
  ensures \result == count_divisors_up_to(n, (z < 0 ? -z : z));
  assigns \nothing;
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
