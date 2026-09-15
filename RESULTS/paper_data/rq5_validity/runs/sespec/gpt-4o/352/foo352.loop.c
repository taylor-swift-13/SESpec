
/*@
  logic integer bitwise_xor(integer a, integer b) =
    (a | b) & ~(a & b);
*/

/*@
  logic integer bitwise_or_accumulator(integer ret, integer total) =
    (total == 0) ? 0 : ((ret % 2 == 0 ? (1 << ret) : 0) | bitwise_or_accumulator(ret + 1, total >> 1));
*/

/*@
  requires number >= 0;
  ensures \result == bitwise_xor(number, bitwise_or_accumulator(0, number));
*/
int foo352(int number) {

    int result = 0;
    int ret = 0;
    int total = number;

    /*@
      loop invariant total >= 0;
      loop invariant (\at(number,Pre) > 0) ==> (total >= 0 && total <= \at(number,Pre));
      loop invariant (!(\at(number,Pre) > 0)) ==> ((total == \at(number,Pre)) && (ret == 0) && (result == 0) && (number == \at(number,Pre)));
      loop invariant number == \at(number,Pre);
      loop assigns result, total, ret;
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
