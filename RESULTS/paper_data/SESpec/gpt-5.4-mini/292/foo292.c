
/*@ logic integer rec(integer n) =
      n == 0 ? 0 :
      n == 1 ? 1 :
      (2 * rec(n - 1) + rec(n - 2)) % 1000000000;
*/

/*@
  requires seed == 1;
  
  ensures seed >= 1 ==> \result >= 0;
  ensures seed == 1 ==> \result == 1;
  ensures seed >= 2 ==> \result == (2 * rec(seed - 1) + rec(seed - 2)) % 1000000000;
*/
int foo292(int seed) {

		int *p = (int *)malloc(sizeof(int) * (seed + 1));
int p_len = seed + 1;
		p[0] = 0;
		p[1] = 1;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant count >= 2;
          loop invariant p[0] == 0;
          loop invariant p[1] == 1;
          loop invariant \forall integer k; 2 <= k < count ==>
                           p[k] == (2 * p[k - 1] + p[k - 2]) % 1000000000;
          loop assigns count, p[0..seed];
            */
            for (int count = 2; count <= seed; count++) {
			p[count] = (2 * p[count - 1]
					+ p[count - 2]) % 1000000000;
		}
            
		return p[seed];
}
