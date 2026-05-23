
/*@
  logic integer pow10(integer e) = (e <= 0 ? 1 : 10 * pow10(e - 1));
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
    while (0) { /* dummy loop to host the required placeholders if any */ }

    return ret;
}
