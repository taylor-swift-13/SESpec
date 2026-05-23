
/*@ 
*/

/*@ logic integer pow2(integer n) = n <= 0 ? 1 : 2 * pow2(n - 1); */
/*@ 
  requires 1 <= c;
  assigns \nothing;
  ensures \result == pow2(c) + (c % 2 == 0 ? 1 : -1);
  ensures c == 1 ==> \result == 1;
  ensures c >= 2 ==> \result > 0;
  ensures \result >= 1;
*/
int foo291(int c) {

		int *j = (int *)malloc(sizeof(int) * (c + 1));
int j_len = c + 1;
		j[0] = 2;
		j[1] = 1;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 2 <= p <= c + 1;
          loop invariant \forall integer i; 2 <= i < p ==> j[i] == j[i - 1] + 2 * j[i - 2];
          loop assigns p, j[2 .. c];
            */
            for (int p = 2; p <= c; p++) {
			j[p] = j[p - 1]
					+ 2 * j[p - 2];
		}
            
		return j[c];
}
