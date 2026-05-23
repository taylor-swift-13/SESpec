
/*@ logic integer fourth_power(integer x) = x * x * x * x; */

/*@ logic integer sum_even_fourths(integer n) =
      n < 1 ? 0 : sum_even_fourths(n - 1) + fourth_power(2 * n);
*/
/*@
   assigns \nothing;
 */
int foo395(int p) {

		int odd = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant p == \at(p,Pre);
          loop invariant 0 <= odd;
          loop assigns odd, c;
          loop variant p - c + 1;
          */
            for (int c = 1; c <= p; c++) {
			int tmp = 2 * c;
			odd = odd + (tmp * tmp * tmp * tmp);
		}
            
		return odd;
}
