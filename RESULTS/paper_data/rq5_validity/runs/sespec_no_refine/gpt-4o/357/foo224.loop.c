
/*@
  logic integer power(integer base, integer exp) =
    exp <= 0 ? 1 : base * power(base, exp - 1);
*/

/*@
  logic integer bit_set(integer x, integer pos) =
    x | (1 << pos);
*/

/*@
  logic integer bit_count(integer x) =
    x == 0 ? 0 : (x & 1) + bit_count(x >> 1);
*/

/*@
  logic integer count_odd_positions_set_bits(integer x) =
    x == 0 ? 0 : ((bit_count(x & 1) % 2 == 1) ? 1 : 0) + count_odd_positions_set_bits(x >> 1);
*/

int foo224(int n) {

    int count = 0;
    int res = 0;
    int temp = n;

    /*@
      loop invariant n == \at(n,Pre);
      loop assigns res, temp, count;
    */
    while (temp > 0) {
        if (count % 2 == 1) {
            res |= (1 << count);
        }
        count++;
        temp >>= 1;
    }

    return (n | res);
}
