
/*@ logic integer decimal_digits(integer n) =
      n <= 0 ? 0 : 1 + decimal_digits(n / 10);
*/

int foo398(int number) {

	int ret = 0;
	
        /*@
          loop invariant ret >= 0;
          loop invariant number <= \at(number,Pre);
          loop invariant ret + decimal_digits(number) == decimal_digits(\at(number,Pre));
          loop assigns number, ret;
        */
        while (number > 0) {
			number /= 10;
			ret++;
		}
            
		return ret;
}
