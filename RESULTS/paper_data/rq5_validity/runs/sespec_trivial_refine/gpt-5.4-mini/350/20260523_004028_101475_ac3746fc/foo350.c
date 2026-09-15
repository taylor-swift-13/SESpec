
/*@
predicate is_even(integer x) = x % 2 == 0;
*/

int foo350(int num) {

    int result = 0;
    int ret = 0;
    int total = num;

    /*@
      loop invariant 0 <= ret;
      loop invariant num <= 0 || total <= num;
      loop invariant total == (num >> ret);
      loop assigns result, ret, total;
    */
    while (total > 0) {
        if (ret % 2 == 0) {
            result = result | (1 << ret);
        }
        ret++;
        total >>= 1;
    }

    return num ^ result;
}
