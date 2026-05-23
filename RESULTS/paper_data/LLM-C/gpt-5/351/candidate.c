/*@ 
  logic integer pow2(integer e) = (e == 0 ? 1 : (e > 0 ? 2 * pow2(e-1) : 0));
  logic integer bitwidth(integer n) = (n <= 0 ? 0 : 1 + bitwidth(n/2));
  logic integer partial_even_mask(integer r) =
    (r <= 0 ? 0 : partial_even_mask(r-1) + (((r-1) % 2 == 0) ? pow2(r-1) : 0));
  logic integer even_mask(integer n) = partial_even_mask(bitwidth(n));
*/

int evenBitToggleNumber(int number);

/*@ 
  assigns \nothing;
  behavior nonpos:
    assumes number <= 0;
    ensures \result == number;
  behavior pos:
    assumes number > 0;
    ensures \result == number ^ even_mask(number);
  complete behaviors nonpos, pos;
  disjoint behaviors nonpos, pos;
*/
int evenBitToggleNumber(int number) {

		int i = 0;
		int ret = 0;
		int total = number;
		/*@
		  loop invariant number > 0;
		  loop invariant 0 <= ret;
		  loop invariant total >= 0;
		  loop invariant total == number / pow2(ret);
		  loop invariant i == partial_even_mask(ret);
		  loop assigns i, ret, total;
		  loop variant total;
		*/
		while (total > 0) {
			if (ret % 2 == 0) {
				i = i | (1 << ret);
			}
			ret++;
			total >>= 1;
		}
		return number ^ i;
}
