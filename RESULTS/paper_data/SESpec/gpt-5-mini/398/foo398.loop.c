
/*@
  // No top-level logic/predicate required.
*/

int foo398(int number) {

    int ret = 0;

    /* >>> LOOP INVARIANT TO FILL <<< */

    /*@
      /* Supplementary invariants: functional progress, monotonicity, existence, exit implication */
      loop invariant 0 <= ret;                                       
      loop invariant number >= 0;                                   
      loop invariant (\at(number,Pre) > 0) ==> (\at(number,Pre) >= number);
      loop invariant (\at(number,Pre) > 0) ==> (ret >= 0);
      loop invariant (\at(number,Pre) > 0) ==> (ret == 0 ==> number == \at(number,Pre));
      loop invariant (\at(number,Pre) > 0) ==> (ret > 0 ==> number < \at(number,Pre));
      loop invariant (\at(number,Pre) > 0) ==> (number < 10 ==> ret >= 1);
      loop invariant (!(\at(number,Pre) > 0)) ==> ((ret == 0) && (number == \at(number,Pre)));
      loop assigns number, ret;
    */
    while (number > 0) {
        number /= 10;
        ret++;
    }

    return ret;
}
