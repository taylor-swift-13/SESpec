
/*@
  logic integer bit_count(integer n) = 
    (n == 0) ? 0 : (n % 2) + bit_count(n / 2);
*/

/*@
  logic integer nth_bit_set(integer n, integer bit) = 
    (n & (1 << bit)) != 0;
*/

/*@
  predicate odd_bit_set(integer n, integer count) = 
    \forall integer i; 0 <= i < count ==> 
      (i % 2 == 1 ==> nth_bit_set(n, i));
*/

/*@
  requires n >= 0;
  assigns \nothing;
  ensures \result == (n | (\at(n,Pre) & (\at(n,Pre) >> 1)));
  ensures odd_bit_set(\result, bit_count(n));
  ensures even_bit_unset(\result, bit_count(n));
*/
int foo224(int n) {

    int count = 0;
    int res = 0;
    int temp = n;

    /*@
      loop invariant (\at(n,Pre) > 0) ==> 
        (temp == \at(n,Pre) >> count) &&
        (res == \at(res,Pre) | (\at(n,Pre) & ((1 << count) - 1))) &&
        (odd_bit_set(res, count)) &&
        (even_bit_unset(res, count));
      loop invariant (!(\at(n,Pre) > 0)) ==> 
        ((temp == \at(n,Pre)) && (res == 0) && (count == 0) && (n == \at(n,Pre)));
      loop invariant temp == \at(n,Pre) >> count;
      loop invariant res == \at(res,Pre) | (\at(n,Pre) & ((1 << count) - 1));
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
