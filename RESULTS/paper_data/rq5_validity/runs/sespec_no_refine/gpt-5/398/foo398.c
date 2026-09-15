
/*@
  assigns \nothing;
  ensures \result == 0 ==> \old(number) <= 0;
  ensures \old(number) <= 0 ==> \result == 0;
  ensures \old(number) > 0 ==> \result >= 1;
  ensures \old(number) > 0 ==> pow10(\result - 1) <= \old(number);
  ensures \old(number) > 0 ==> pow10(\result) > \old(number);
*/
int foo398(int number) {
    int ret = 0;
    /*@
      loop invariant ret >= 0;
      loop invariant number <= \at(number,Pre);
      loop assigns number, ret;
    */
    while (number > 0) {
        number /= 10;
        ret++;
    }
    /*@
      loop assigns number, ret;
    */
    while (0) { }
    return ret;
}
