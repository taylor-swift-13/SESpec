
/*@ 
  logic integer shr(integer x, integer k) =
    k <= 0 ? x : shr(x / 2, k - 1);

  logic integer odd_bits_prefix(integer orig, integer e) =
    e <= 0 ? 0
    : (odd_bits_prefix(orig, e-1) | (( ( (orig >> (e-1)) & 1) && ((e-1) % 2 == 1) ) ? (1 << (e-1)) : 0));
*/

/*@
  requires \true;
  assigns \nothing;
  ensures (\result | num) == \result;
*/
int foo353(int num) {

		int result = 0;
		int max = 0;
		int sum = num;
		
            
        /*@
          loop invariant 0 <= result;
          loop invariant (\at(num,Pre) > 0) ==> (result >= 0);
          loop invariant (!(\at(num,Pre) > 0)) ==> ((sum == \at(num,Pre))&&(max == 0)&&(result == 0)&&(num == \at(num,Pre)));
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
