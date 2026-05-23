
/*@
  logic integer count_divisors(integer num, integer limit) =
    (limit <= 0) ? 0 : (num % limit == 0 ? 1 : 0) + count_divisors(num, limit - 1);
*/

/*@
  logic integer total_divisors(integer num, integer z) =
    count_divisors(num, z);
*/

/*@
  requires \true;
  assigns z, result;
  ensures z == (\at(z, Pre) < 0 ? -\at(z, Pre) : \at(z, Pre));
  ensures \result == total_divisors(num, z);
*/
int foo190(int num, int z) {

    if (z < 0) {
        z = -z;
    }
    int result = 0;

    /*@
      loop invariant 1 <= index <= z + 1;
      loop invariant result == count_divisors(num, index - 1);
      loop invariant z == \at(z, Pre);
      loop invariant num == \at(num, Pre);
      loop assigns index, result;
      loop variant z - index;
    */
    for (int index = 1; index <= z; index++) {
        if (num % index == 0) {
            result = result + 1;
        }
    }

    return result;
}
