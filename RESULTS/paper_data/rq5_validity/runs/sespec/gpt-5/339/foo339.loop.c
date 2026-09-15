
/* No extra predicates or logic functions are needed. */

int foo339(int num, int z) {

    if (z < 0) {
        z = -z;
    }
    int result = 0;

    /*@
      loop invariant 1 <= index <= z + 1;
      loop invariant 0 <= result <= index - 1;
      loop invariant \forall integer k; 1 <= k < index ==> k <= z;
      loop invariant \forall integer k; 1 <= k < index ==> ((num % k == 0) ==> 0 <= result);
      loop invariant \forall integer k; 1 <= k < index ==> ((num % k != 0) ==> 0 <= result);
      loop invariant \forall integer k; 1 <= k < index ==> ((num % k == 0) ==> result <= index - 1);
      loop invariant \forall integer k; 1 <= k < index ==> ((num % k != 0) ==> result <= index - 1);
      loop invariant \forall integer k; 1 <= k < index ==> (k <= z);
      loop invariant \exists integer m; m == result && 0 <= m <= index - 1;
      loop invariant \forall integer k; 1 <= k < index ==> ((num % k == 0) ==> 1 <= result + 1);
      loop invariant \forall integer k; 1 <= k < index ==> ((num % k != 0) ==> result == result);
      loop invariant \forall integer k; 1 <= k < index ==> (num % k == 0 || num % k != 0);
      loop invariant (index <= \at(z,Pre)) ==> (0 <= index && index <= z);
      loop invariant (index <= \at(z,Pre)) ==> (0 <= result && result <= index - 1);
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
