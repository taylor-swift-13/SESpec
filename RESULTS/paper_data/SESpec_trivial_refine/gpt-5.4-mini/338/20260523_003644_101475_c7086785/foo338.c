
/*@
*/

predicate divides(integer a, integer b) = b != 0 && a % b == 0;


/*@
  requires num > 0;
  assigns \nothing;
  ensures \old(num) == 1 ==> \result == 0;
  ensures \old(num) > 1 ==> \result > 0;
  ensures \result == 0 ==> \old(num) == 1;
  ensures \result > 0 ==> divides(\old(num), \result);
  ensures \result > 0 ==> \forall integer d; 2 <= d < \result ==> \result % d != 0;
  ensures \result > 0 ==> \result <= \old(num);
*/
int foo338(int num) {

		int result = 0;
		
            /*@
          loop invariant num > 0;
          loop invariant result == 0 || result >= 2;
          loop assigns j, result, num;
            */
            for (int j = 2; j <= num; j++) {
			
            /*@
          loop invariant j >= 2;
          loop invariant num > 0;
          loop invariant result == 0 || result >= 2;
          loop assigns result, num;
            */
            while (num % j == 0) {
				result = j;
				num /= j;
			}
            
		}
            
		return result;
}
