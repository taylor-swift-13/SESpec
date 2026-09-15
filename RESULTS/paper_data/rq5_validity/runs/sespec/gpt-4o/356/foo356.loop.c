
/*@
  logic integer bitwise_or_accumulator(integer n, integer count) =
    (count == 0) ? 0 : ((count % 2 == 0) ? (1 << (count - 1)) | bitwise_or_accumulator(n >> 1, count - 1) : bitwise_or_accumulator(n >> 1, count - 1));
*/

/*@
  requires n >= 0; // Strengthened precondition to ensure valid loop entry
*/
int foo356(int n) {
    int res = 0;
    int count = 0;
    int temp = n;

    /*@
      loop invariant temp >= 0;
      loop invariant count >= 0;
      loop invariant temp == n >> count;
      loop invariant (\forall integer k; 0 <= k < count ==> (k % 2 == 0 ==> ((res & (1 << k)) != 0)));
      loop invariant (!(\at(n,Pre) > 0)) ==> ((temp == \at(n,Pre)) && (count == 0) && (res == 0) && (n == \at(n,Pre)));
      loop assigns res, temp, count;
    */
    while (temp > 0) {
        if (count % 2 == 0) {
            res = res | (1 << count);
        }
        count++;
        temp >>= 1;
    }

    return n ^ res;
}
