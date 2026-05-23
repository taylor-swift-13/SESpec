
/*@
  logic integer count_divisors(integer num, integer limit) =
    limit <= 0 ? 0 : (num % limit == 0 ? 1 : 0) + count_divisors(num, limit - 1);
*/

/*@
  requires z >= 0 ==> (z == \at(z, Pre) && num == \at(num, Pre));
  requires z < 0 ==> (z == -\at(z, Pre) && num == \at(num, Pre));
  assigns \nothing;
  ensures \result == count_divisors(num, z >= 0 ? z : -z);
*/
int foo339(int num, int z) {

    if (z < 0) {
        z = -z;
    }
    int result = 0;

    /*@
      loop invariant 1 <= index <= z + 1;
      loop invariant result == count_divisors(num, index - 1);
      loop invariant z >= 0;
      loop invariant num == \at(num, Pre);
      loop assigns index, result;
    */
    for (int index = 1; index <= z; index++) {
        if (num % index == 0) {
            result = result + 1;
        }
    }

    return result;
}
