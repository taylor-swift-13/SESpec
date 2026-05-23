
/*@ 
  logic integer power10(integer k) =
    k <= 0 ? 1 : 10 * power10(k - 1);
*/

/*@
  requires result == 0;    // as stated in the problem pre-condition
  requires value == \at(value,Pre);
*/
int foo325(int value) {

		int result = 0;
		
        /*@
          loop invariant 0 <= result;
          loop invariant value >= 0;
          loop invariant (\at(value,Pre) > 0) ==> (value * power10(result) + (\at(value,Pre) % power10(result)) == \at(value,Pre));
          loop invariant (\at(value,Pre) > 0) ==> (value == \at(value,Pre) / power10(result));
          loop invariant (\at(value,Pre) > 0) ==> (result >= 0);
          loop invariant (!(\at(value,Pre) > 0)) ==> ((result == 0)&&(value == \at(value,Pre)));
          loop assigns value, result;
        */
            while (value > 0) {
			value /= 10;
			result++;
		}
            
		return result;
}
