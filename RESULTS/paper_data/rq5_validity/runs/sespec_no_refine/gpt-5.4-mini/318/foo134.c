
/*@
  assigns \nothing;
  ensures \result == 1;
  ensures num == 1 ==> \result == 1;
  ensures num != 1 ==> \result >= 0;
*/
int foo134(int num) {

		int result = 0;
		if (num == 1)
			return 1;
		
        /*@
          loop invariant 2 <= c;
          loop invariant result >= 0;
          loop invariant result <= c - 2;
          loop invariant c <= num / c + 1;
          loop assigns c, result;
        */
            /*@
          loop invariant (!(c <= num / c)) ==> ();
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
