
/*@
  assigns \nothing;
  ensures z >= 0 ==>
           \result == count_divisors_prefix(num, z + 1);
  ensures z < 0 ==>
           \result == count_divisors_prefix(num, (-z) + 1);
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
