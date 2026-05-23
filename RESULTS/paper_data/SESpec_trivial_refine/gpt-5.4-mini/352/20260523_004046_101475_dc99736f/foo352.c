
/*@
  assigns \nothing;
  ensures number <= 0 ==> \result == number;
*/
int foo352(int number) {

    int result = 0;
    int ret = 0;
    int total = number;

    if (number <= 0) {
        return number;
    }

    /*@
      loop invariant ret >= 0;
      loop invariant total == (number >> ret);
      loop invariant total >= 0;
      loop assigns result, ret, total;
      loop variant total;
    */
    while (total > 0) {
        if (ret % 2 == 0) {
            result = result | (1 << ret);
        }
        ret++;
        total >>= 1;
    }

    return number ^ result;
}
