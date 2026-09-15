
/*@ logic integer digits10(integer n) =
      n <= 0 ? 0 : 1 + digits10(n / 10); */
/*@
  assigns \nothing;
  ensures \result == digits10(\old(number));
  ensures \result >= 0;
*/
int foo398(int number) {
    int ret = 0;
    int n0 = number;

    /*@
      loop invariant ret + digits10(number) == digits10(n0);
      loop invariant ret >= 0;
      loop assigns number, ret;
    */
    while (number > 0) {
        number /= 10;
        ret++;
    }

    return ret;
}
