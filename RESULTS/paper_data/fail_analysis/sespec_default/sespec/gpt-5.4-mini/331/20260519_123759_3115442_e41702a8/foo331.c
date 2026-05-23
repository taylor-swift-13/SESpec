
/*@ 
  assigns \nothing;
  ensures (n == c) ==> \result == 1;
  ensures (n != c && (c - n) >= 5) ==> \result == 0;
*/
int foo331(int n, int c) {

		int result = 1;
		if (n == c) {
			return 1;
		} else if ((c - n) >= 5) {
			return 0;
		} else {
			
            /*@
          loop invariant n == \at(n,Pre);
          loop invariant c == \at(c,Pre);
          loop invariant index >= n + 1;
          loop assigns index, result;
            */
            for (int index = n + 1; index < c + 1; index++) {
				result = (result * (index % 10)) % 10;
			}
            
			return result % 10;
		}
}
