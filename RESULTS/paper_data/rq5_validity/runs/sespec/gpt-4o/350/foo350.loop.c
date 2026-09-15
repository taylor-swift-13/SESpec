
/*@
  logic integer compute_result(integer num, integer ret) =
    (\sum integer k; 0 <= k < ret && k % 2 == 0; (1 << k));
*/

/*@
  logic integer compute_total(integer num, integer ret) =
    num >> ret;
*/

int foo350(int num) {

    int result = 0;
    int ret = 0;
    int total = num;

    /*@
      loop invariant 0 <= total <= \at(num, Pre);
      loop invariant 0 <= ret;
      loop invariant result == compute_result(\at(num, Pre), ret);
      loop invariant total == compute_total(\at(num, Pre), ret);
      loop invariant (\at(num, Pre) > 0) ==> (result == compute_result(\at(num, Pre), ret));
      loop invariant (\at(num, Pre) > 0) ==> (ret == (\at(num, Pre) - total));
      loop invariant (!(\at(num, Pre) > 0)) ==> ((total == \at(num, Pre)) && (ret == 0) && (result == 0) && (num == \at(num, Pre)));
      loop assigns result, total, ret;
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
