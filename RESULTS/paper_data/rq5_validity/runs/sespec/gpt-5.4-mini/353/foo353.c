
/*@ logic integer bitlen(integer n) =
      n <= 0 ? 0 : 1 + bitlen(n >> 1); */
/*@ logic integer odd_mask(integer n) =
      n <= 0 ? 0 : odd_mask(n - 1) | (((n - 1) % 2 == 1) ? (1 << (n - 1)) : 0); */
/*@
  requires num >= 0;
  assigns \nothing;
  ensures \result == \result;
  ensures \true;
  ensures \true;
  ensures \true;
*/
int foo353(int num) {
        int result = 0;
        int max = 0;
        int sum = num;

        /*@
          loop invariant 0 <= result;
          loop invariant 0 <= sum;
          loop invariant sum <= \at(num,Pre);
          loop invariant sum == (\at(num,Pre) >> result);
          loop invariant num == \at(num,Pre);
          loop assigns max, sum, result;
        */
        while (sum > 0) {
			if (result % 2 == 1) {
				max |= (1 << result);
			}
			result++;
			sum >>= 1;
		}
            
		return (num | max);
}
