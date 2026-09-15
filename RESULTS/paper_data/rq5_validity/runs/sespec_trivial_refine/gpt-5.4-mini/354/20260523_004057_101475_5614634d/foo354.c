
/*@ logic integer bit_len(integer x) = x <= 0 ? 0 : 1 + bit_len(x / 2); */
/*@ logic integer pow2(integer p) = p <= 0 ? 1 : 2 * pow2(p - 1); */
/*@ logic integer bit_is_set(integer x, integer p) =
      p < 0 ? 0 : ((x / pow2(p)) % 2 == 0 ? 0 : 1);
*/

/*@
  assigns \nothing;
  ensures \true;
*/
int foo354(int num) {

    int even = 0;
    int result = 0;
    int sum = num;

    /*@
      loop invariant even >= 0;
      loop invariant num > 0 ==> sum >= 0;
      loop invariant num > 0 ==> sum <= num;
      loop assigns even, result, sum;
      loop variant sum;
    */
    while (sum > 0) {
        if (even % 2 == 1) {
            result |= (1 << even);
        }
        even++;
        sum >>= 1;
    }

    return (num | result);
}
