int difference(int diff);

/*@
  requires diff <= 303;
  assigns \nothing;

  behavior nonpositive:
    assumes diff <= 0;
    ensures \result == 0;

  behavior positive:
    assumes 1 <= diff && diff <= 303;
    ensures \result ==
      (\sum integer j; 1 <= j <= diff; j*j*j)
      - (\sum integer j; 1 <= j <= diff; j);

  complete behaviors nonpositive, positive;
  disjoint behaviors nonpositive, positive;
*/
int difference(int diff) {

		int ret = 0;
		int max = 0;
		/*@
		  loop invariant j >= 1;
		  loop invariant j <= (diff >= 1 ? diff + 1 : 1);
		  loop invariant ret == (\sum integer k; 1 <= k < j; k*k*k);
		  loop assigns j, ret;
		  loop variant (diff >= 1 ? diff - j + 1 : 0);
		*/
		for (int j = 1; j <= diff; j++) {
			ret += j * j * j;
		}
		/*@
		  loop invariant j >= 1;
		  loop invariant j <= (diff >= 1 ? diff + 1 : 1);
		  loop invariant max == (\sum integer k; 1 <= k < j; k);
		  loop assigns j, max;
		  loop variant (diff >= 1 ? diff - j + 1 : 0);
		*/
		for (int j = 1; j <= diff; j++) {
			max += j;
		}
		return ret - max;
}
