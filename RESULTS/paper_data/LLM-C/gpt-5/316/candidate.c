int countFac(int number);

/*@
  requires number >= 0;
  assigns \nothing;
  ensures \result ==
          (number == 1 ? 1 :
           \sum integer c; 2 <= c <= number;
             ((c <= number / c) && (number % c == 0) ? 1 : 0));
  ensures \result >= 0;
*/
int countFac(int number) {

		int result = 0;
		if (number == 1)
			return 1;
		/*@
		  loop invariant 2 <= c;
		  loop invariant result ==
		    \sum integer d; 2 <= d < c; (number % d == 0 ? 1 : 0);
		  loop invariant result >= 0;
		  loop assigns result, c;
		  loop variant number - c;
		*/
		for (int c = 2; c <= number / c; c++) {
			if (number % c == 0) {
				result++;
				if (number / c == c) {
					break;
				}
			}
		}
		return result;
}
