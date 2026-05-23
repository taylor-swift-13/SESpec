/*@ 
  logic integer tri(integer n) = n * (n + 1) / 2;

  requires diff <= 303;
  assigns \nothing;

  behavior nonpos:
    assumes diff <= 0;
    ensures \result == 0;

  behavior pos:
    assumes 1 <= diff <= 303;
    ensures \result == tri(diff) * tri(diff) - tri(diff);

  complete behaviors;
  disjoint behaviors;
*/
int difference(int diff);

int difference(int diff) {

		int result = 0;
		int max = 0;
		/*@ 
		  loop invariant 1 <= c <= diff + 1;
		  loop invariant 0 <= result;
		  loop invariant result == tri(c - 1) * tri(c - 1);
		  loop assigns c, result;
		  loop variant diff - c + 1;
		*/
		for (int c = 1; c <= diff; c++) {
			result += c * c * c;
		}
		/*@ 
		  loop invariant 1 <= c <= diff + 1;
		  loop invariant 0 <= max;
		  loop invariant max == tri(c - 1);
		  loop assigns c, max;
		  loop variant diff - c + 1;
		*/
		for (int c = 1; c <= diff; c++) {
			max += c;
		}
		return result - max;
}
