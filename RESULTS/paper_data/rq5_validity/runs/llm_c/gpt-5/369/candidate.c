int findMaxVal(int value, int p, int dy);

/*@ 
  requires p > 0;
  requires value < INT_MAX;
  assigns \nothing;

  ensures \result == 0 <==> (\forall integer t; 1 <= t && t <= value ==> t % p != dy);
  ensures \result != 0 ==> (1 <= \result && \result <= value && \result % p == dy);
  ensures \forall integer t; 1 <= t && t <= value && t % p == dy ==> t <= \result;
  ensures (dy < 0 || dy >= p) ==> \result == 0;
*/
int findMaxVal(int value, int p, int dy) {

		int result = 0;
		/*@
		  loop invariant 1 <= c && c <= value;
		  loop invariant 0 <= result;
		  loop invariant result == 0 || (1 <= result && result < c && result % p == dy);
		  loop invariant \forall integer t; 1 <= t && t < c && t % p == dy ==> t <= result;
		  loop assigns result, c;
		  loop variant value - c + 1;
		*/
		for (int c = 1; c <= value; c++) {
			/*@ assert 0 <= c % p < p; */
			if ((c % p) == dy) {
				result = c;
			}
		}
		return result;
}
