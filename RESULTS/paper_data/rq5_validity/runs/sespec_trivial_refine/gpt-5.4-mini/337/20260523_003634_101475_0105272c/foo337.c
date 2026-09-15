
/*@
  assigns \nothing;
  ensures \result >= 0;
  ensures \result == 0 || \result >= 2;
*/
int foo337(int num) {
    int ret = 0;
    int j;

    /*@
      loop invariant j >= 2;
      loop invariant ret == 0 || ret >= 2;
      loop invariant ret >= 0;
      loop assigns j, ret, num;
    */
    for (j = 2; j <= num; j++) {

        /*@
          loop invariant ret == 0 || ret >= 2;
          loop invariant ret >= 0;
          loop assigns ret, num;
        */
        while (num % j == 0) {
            ret = j;
            num /= j;
        }
    }

    return ret;
}
