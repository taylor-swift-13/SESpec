int findMaxVal(int value, int p, int z);

/*@ 
  requires p != 0;
  assigns \nothing;
  ensures 0 <= \result;
  ensures (\result > 0) ==> (1 <= \result && \result <= value);
  ensures (!(\exists integer c; 1 <= c <= value && c % p == z)) ==> \result == 0;
  ensures (\exists integer c; 1 <= c <= value && c % p == z) ==> (\result % p == z);
  ensures \forall integer c; 1 <= c <= value && c % p == z ==> c <= \result;
*/
int findMaxVal(int value, int p, int z) {

		int result = 0;
		/*@
		  loop invariant 1 <= c <= value + 1;
		  loop invariant 0 <= result;
		  loop invariant result == 0 || result % p == z;
		  loop invariant result < c;
		  loop invariant \forall integer t; 1 <= t < c && t % p == z ==> t <= result;
		  loop invariant (result == 0) <==> !(\exists integer t; 1 <= t < c && t % p == z);
		  loop assigns c, result;
		  loop variant (c <= value ? value - c + 1 : 0);
		*/
		for (int c = 1; c <= value; c++) {
			if ((c % p) == z) {
				result = c;
			}
		}
		return result;
}
