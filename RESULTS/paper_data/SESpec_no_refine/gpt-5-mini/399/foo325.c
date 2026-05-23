
/*@ 
  logic integer power10(integer k) =
    k <= 0 ? 1 : 10 * power10(k - 1);
*/

/*@ 
  logic integer digit_count(integer v) =
    v <= 0 ? 0 : 1 + digit_count(v / 10);
*/
/*@
  requires \true;
  assigns \nothing;   
  ensures (\at(value,Pre) <= 0) ==> (\result == 0 && value == \at(value,Pre));
  ensures \result >= 0;
*/
int foo325(int value) {

		int result = 0;
		
        /*@
          loop invariant 0 <= result;
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
