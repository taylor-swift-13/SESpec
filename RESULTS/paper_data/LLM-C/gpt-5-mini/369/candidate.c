int findMaxVal(int value, int p, int dy);

/*@
    requires value >= 0;
    requires p > 0;
    requires 0 <= dy < p;
    assigns \nothing; // temporary; overridden by behavior which assigns result
    behavior normal:
        assigns \result;
        ensures 0 <= \result <= value;
        ensures \result == 0 <==> (\forall integer j; 1 <= j <= value ==> j % p != dy);
        ensures \result != 0 ==> (1 <= \result <= value && \result % p == dy &&
                                   (\forall integer j; 1 <= j <= value && j % p == dy ==> j <= \result));
    complete behaviors normal;
    disjoint behaviors normal;
*/
int findMaxVal(int value, int p, int dy) {

		int result = 0;
		/*@
		    loop invariant 1 <= c <= value + 1;
		    loop invariant 0 <= result <= value;
		    loop invariant (\forall integer j; 1 <= j < c && j % p == dy ==> j <= result);
		    loop invariant (result == 0) <==> (\forall integer j; 1 <= j < c ==> j % p != dy);
		    loop assigns c, result;
		    loop variant value - c + 1;
		*/
		for (int c = 1; c <= value; c++) {
			if ((c % p) == dy) {
				result = c;
			}
		}
		return result;
}
