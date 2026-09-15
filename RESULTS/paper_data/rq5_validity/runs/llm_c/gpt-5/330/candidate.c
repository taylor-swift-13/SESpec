int difference(int diff);

/*@ 
  requires diff <= 303;
  assigns \nothing;

  behavior nonpos:
    assumes diff <= 0;
    ensures \result == 0;

  behavior pos:
    assumes 1 <= diff <= 303;
    ensures \result == ((diff * (diff + 1)) / 2) * ((diff * (diff + 1)) / 2) - (diff * (diff + 1)) / 2;

  complete behaviors;
  disjoint behaviors;
*/
int difference(int diff) {

		int result = 0;
		int max = 0;
		/*@
		  loop invariant 1 <= j;
		  loop invariant (diff < 1 ==> j == 1);
		  loop invariant (diff >= 1 ==> j <= diff + 1);
		  loop invariant result == ((j - 1) * j / 2) * ((j - 1) * j / 2);
		  loop invariant result >= 0;
		  loop assigns j, result;
		  loop variant (diff > 0 ? diff - j + 1 : 0);
		*/
		for (int j = 1; j <= diff; j++) {
			result += j * j * j;
		}
		/*@
		  loop invariant 1 <= j;
		  loop invariant (diff < 1 ==> j == 1);
		  loop invariant (diff >= 1 ==> j <= diff + 1);
		  loop invariant max == (j - 1) * j / 2;
		  loop invariant max >= 0;
		  loop assigns j, max;
		  loop variant (diff > 0 ? diff - j + 1 : 0);
		*/
		for (int j = 1; j <= diff; j++) {
			max += j;
		}
		return result - max;
}
