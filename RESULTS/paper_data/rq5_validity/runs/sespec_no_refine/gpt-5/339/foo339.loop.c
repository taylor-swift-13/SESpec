
/*@
  // A logic function that counts how many integers in [1 .. k-1] divide n.
  logic integer count_divisors_prefix(integer n, integer k) =
    (k <= 1 ? 0
            : count_divisors_prefix(n, k - 1) + (((k - 1) != 0 && n % (k - 1) == 0) ? 1 : 0));
*/

int foo339(int num, int z) {

    if (z < 0) {
        z = -z;
    }
    int result = 0;

    /*@
      loop invariant 1 <= index <= z + 1;
      loop invariant z >= 0;
      loop invariant num == \at(num,Pre);
      loop assigns index, result;
    */
    for (int index = 1; index <= z; index++) {
        if (num % index == 0) {
            result = result + 1;
        }
    }

    return result;
}
