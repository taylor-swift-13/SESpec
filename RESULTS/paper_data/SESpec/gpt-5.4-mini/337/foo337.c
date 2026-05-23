
/*@ predicate prime(integer n) =
      n >= 2 &&
      \forall integer d; 2 <= d < n ==> n % d != 0;
*/
/*@ 
  requires num >= 0;
  assigns \nothing;
  ensures \true;
  ensures \true;
  ensures \true;
  ensures \true;
  ensures \true;
*/
int foo337(int num) {

		int ret = 0;
		
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
              loop invariant j >= 2;
              loop invariant 0 <= ret <= j;
              loop assigns j, ret, num;
            */
            for (int j = 2; j <= num; j++) {
			
            /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
              loop invariant j >= 2;
              loop invariant 0 <= ret <= j;
              loop assigns ret, num;
            */
            while (num % j == 0) {
				ret = j;
				num /= j;
			}
            
		}
            
		return ret;
}
