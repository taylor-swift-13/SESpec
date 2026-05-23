
/*@
  logic integer div10_pow(integer x, integer n) =
    n <= 0 ? x : div10_pow(x / 10, n - 1);
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

    return ret;
}
