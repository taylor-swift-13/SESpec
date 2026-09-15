
        /*@ logic integer bit_length(integer n) =
      n <= 0 ? 0 : 1 + bit_length(n / 2); */
/*@ logic integer odd_bits(integer k) =
      k <= 0 ? 0 : (((k % 2) == 1) ? (1 << (k - 1)) : 0) + odd_bits(k - 1); */
/*@
  assigns \nothing;
  ensures num <= 0 ==> \result == num;
  ensures num > 0  ==> \result == (num | odd_bits(bit_length(num)));
*/
int foo353(int num) {
  if (num <= 0) {
    return num;
  }

  int result = 0;
  int max = 0;
  int sum = num;

  /*@
    loop invariant result >= 0;
    loop invariant sum >= 0;
    loop invariant max == odd_bits(result);
    loop invariant bit_length(sum) + result == bit_length(num);
    loop assigns result, max, sum;
    loop variant sum;
  */
  while (sum > 0) {
    if (result % 2 == 0) {
      max += (1 << result);
    }
    result++;
    sum /= 2;
  }

  return (num | max);
}
