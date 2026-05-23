


/*@
  requires \true;
  assigns \nothing;
  ensures \result == 0 <==> \at(value,Pre) <= 0;
  ensures \at(value,Pre) > 0 ==> \result >= 1;
  ensures \at(value,Pre) > 0 ==> \at(value,Pre) / 1 > 0;
  ensures \at(value,Pre) > 0 ==> \at(value,Pre) / (1) > 0;
*/
int foo399(int value) {

    int result = 0;

    /*@
      loop invariant 0 <= result;

      loop invariant value == 0 ==> (result >= 1 || \at(value,Pre) == 0);
      loop invariant result == 0 ==> value == \at(value,Pre);
      loop invariant result > 0 ==> value < \at(value,Pre);
      loop invariant value > 0 ==> \at(value,Pre) >= 1;
      loop invariant value > 0 ==> \at(value,Pre) / 10 <= \at(value,Pre);

      loop invariant (\at(value,Pre) > 0) ==> (0 <= value && value <= \at(value,Pre));
      loop invariant (!(\at(value,Pre) > 0)) ==> ((result == 0)&&(value == \at(value,Pre)));
      loop assigns value, result;
    */
    while (value > 0) {
        value /= 10;
        result++;
    }

    return result;
}
