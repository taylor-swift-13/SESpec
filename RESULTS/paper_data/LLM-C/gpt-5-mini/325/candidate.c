/*@
    requires 0 <= num <= 12;
    assigns \nothing;
    ensures 0 <= \result <= 9;
    ensures \result == \mod(\product integer k; 1 <= k <= num; k, 10);
*/
int firstDigit(int num);

int firstDigit(int num) {

		int first = 1;
		/*@ 
		    loop invariant 2 <= j;
		    loop invariant first == \product integer k; 1 <= k <= j-1; k;
		    loop assigns j, first;
		    loop variant num - j + 2;
		*/
		for (int j = 2; j <= num; j++) {
			first *= j;
		}
		int result = 0;
		/*@
		    loop invariant 0 <= result <= 9;
		    loop invariant first >= 0;
		    loop invariant \product integer t; 1 <= t <= num; t == first * (\product integer u; 1 <= u <= (\exists integer m; 0 <= m; /* placeholder */ 1) ; 10) + result
		        || \exists integer m; m >= 0 && \product integer t; 1 <= t <= num; t == first * (\product integer u; 1 <= u <= m; 10) + result;
		    loop assigns first, result;
		    loop variant first;
		*/
		while (first > 0) {
			result = first % 10;
			first /= 10;
		}
		return result;
}
