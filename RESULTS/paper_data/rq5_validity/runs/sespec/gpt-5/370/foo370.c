
/*@
  assigns \nothing;
  ensures (\result == 0) || ((\result % k) == z);
  ensures (\result == 0) ==> (\forall integer t; 1 <= t <= value ==> ((t % k) != z));
  ensures (\result != 0) ==> ((\result % k) == z);
  ensures (\result != 0) ==> (\forall integer t; \result < t <= value ==> ((t % k) != z));
  ensures value == \old(value);
  ensures k == \old(k);
  ensures z == \old(z);
*/
int foo370(int value, int k, int z) {

    int result = 0;

    /*@
      loop invariant (result != 0) ==> ((result % \at(k,Pre)) == \at(z,Pre));
      loop invariant (result != 0) ==> (\forall integer t; result < t <= c - 1 ==> (t % \at(k,Pre)) != \at(z,Pre));
      loop invariant (\forall integer t; 1 <= t <= c - 1 ==> (((t % \at(k,Pre)) == \at(z,Pre)) ==> t <= (result == 0 ? 0 : result)));
      loop invariant (c == \at(value,Pre) + 1) ==> ((result == 0) || ((result % \at(k,Pre)) == \at(z,Pre) && (\forall integer t; result < t && t <= \at(value,Pre) ==> (t % \at(k,Pre)) != \at(z,Pre))));
      loop invariant z == \at(z,Pre);
      loop invariant k == \at(k,Pre);
      loop invariant value == \at(value,Pre);
      loop assigns c, result;
    */
    for (int c = 1; c <= value; c++) {
        if ((c % k) == z) {
            result = c;
        }
    }

    return result;
}
