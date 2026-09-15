int firstDigit(int num);

/*@ 
  logic integer fact(integer n) = (n <= 1) ? 1 : n * fact(n - 1);

  logic integer msd(integer x) = (x < 10) ? x : msd(x / 10);
*/

/*@ 
  requires 0 <= num <= 12;
  assigns \nothing;
  ensures \result == msd(fact(num));
  ensures 1 <= \result <= 9;
*/
int firstDigit(int num) {

		int first = 1;
		/*@ 
		  loop invariant 2 <= c <= num + 1;
		  loop invariant first == fact(c - 1);
		  loop invariant first >= 1;
		  loop variant num - c + 1;
		*/
		for (int c = 2; c <= num; c++) {
			first *= c;
		}
		/*@ assert first == fact(num); */
		int result = 0;
		/*@ 
		  loop invariant first >= 0;
		  loop invariant 0 <= result <= 9;
		  loop variant first;
		*/
		while (first > 0) {
			result = first % 10;
			first /= 10;
		}
		return result;
}
