
/*@
  assigns \nothing;
  ensures size == \old(size);
  ensures size > 1 ==> \result == size / 2 + 1;
  ensures size > 1 ==> \result >= 1;
  ensures size > 1 ==> \result <= size;
*/
int foo362(int size) {

		int result = 0;
		int total = 0;
		
            /*@
          loop invariant 1 <= c;
          loop invariant c == 1 || c <= size + 1;
          loop invariant 0 <= total;
          loop invariant 0 <= result;
          loop invariant result % 2 == 0;
          loop invariant result >= 2 * total;
          loop invariant total <= c / 2;
          loop invariant c == 1 || total <= (c - 1) / 2;
          loop invariant result == 0 || result >= total;
          loop invariant (c <= \at(size,Pre)) ==> (result >= 0);
          loop invariant (c <= \at(size,Pre)) ==> (total >= 0);
          loop invariant result == total * (total + 1);
          loop invariant c == 2 * total + 1 || c == 2 * total + 2;
          loop invariant size == \at(size,Pre);
          loop assigns c, result, total;
            */
            for (int c = 1; c <= size; c++) {
			if (c % 2 == 0) {
				result += c;
				total++;
			}
		}
            
		return result / total;
}
