
/*@ logic integer count_divs_checked(integer n, integer c) =
      c <= 1 ? 0 :
      count_divs_checked(n, c - 1) + (c <= n / c && n % c == 0 ? 1 : 0);
*/
/*@
  requires num >= 0;
  assigns \nothing;
  ensures num == 1 ==> \result == 1;
  ensures num != 1 ==> \result >= 0;
  ensures \result >= 0;
  ensures num != 1 ==> (\result == 0 ==> \true);
*/
int foo318(int num) {

		int result = 0;
		if (num == 1)
			return 1;
		
        /*@
          loop invariant 2 <= c;
          loop invariant 0 <= result;
          loop invariant result <= c - 2;
          
          loop assigns c, result;
        */
        for (int c = 2; c <= num / c; c++) {
			if (num % c == 0) {
				result++;
				if (num / c == c) {
					break;
				}
			}
		}
            
		return result;
}
