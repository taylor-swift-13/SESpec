
/*@ 
  logic integer decimal_digits(integer n) = 
    n < 0 ? decimal_digits(-n) :
    n < 10 ? 1 :
    1 + decimal_digits(n / 10);
*/

/*@
  requires number > 0;
  assigns \nothing;
  
  ensures \result >= 0;
  ensures \result == decimal_digits(\old(number));
*/
int foo398(int number) {

	int ret = 0;
	
        /*@
          loop invariant ret >= 0;
          loop invariant number <= \at(number,Pre);
          loop invariant number >= 0;
          loop invariant number > 0 ==> ret + decimal_digits(number) == decimal_digits(\at(number,Pre));
          loop invariant number == 0 ==> ret == decimal_digits(\at(number,Pre));
          loop assigns number, ret;
        */
        while (number > 0) {
			number /= 10;
			ret++;
		}
            
		return ret;
}
