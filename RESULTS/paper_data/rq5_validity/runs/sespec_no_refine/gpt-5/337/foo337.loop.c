
/*@
  // no additional predicates or logic functions needed
*/

/*@
  requires num >= 0;
  ensures \result == 0 || (\exists integer p; p >= 2 && \result == p && num % p == 0);
*/

int foo337(int num) {

		int ret = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
              loop invariant num >= 0;
              loop invariant ret == 0 || (\exists integer p; 2 <= p < j && ret == p && num % p == 0);
              loop invariant \forall integer k; 2 <= k < j ==> num % k != 0 || ret == k;
              loop assigns j, ret, num;
            */
            for (int j = 2; j <= num; j++) {
			
        /* >>> LOOP INVARIANT TO FILL <<< */
            /*@
              loop invariant num >= 0;
              loop invariant ret == 0 || (2 <= ret <= j && num % ret == 0);
              loop invariant \forall integer k; 2 <= k < j ==> num % k != 0;
              loop assigns ret, num;
            */
            while (num % j == 0) {
				ret = j;
				num /= j;
			}
            
		}
            
		return ret;
}
