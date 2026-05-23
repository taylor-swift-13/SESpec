
/*@
logic integer catalan_partial_sum(int *catalan, integer i, integer j) =
  \sum(integer k = 0; k < j; catalan[k] * catalan[i - k - 1]);
*/
/*@
logic integer catalan_partial_sum(int *catalan, integer i, integer j) =
  \sum(integer k = 0; k < j; catalan[k] * catalan[i - k - 1]);
*/

        /*@
        */
        

/*@
  requires num >= 0;
  requires num <= 2147483646;
*/

int foo214(int num) {

        int *catalan = (int *)malloc(sizeof(int) * (num + 1));
        int catalan_len = num + 1;
        catalan[0] = 1;
        
            
        /*@
          loop assigns i, catalan[1..num];
          loop invariant 1 <= i <= num + 1;
          loop invariant catalan[0] == 1;
        */
        
            /*@
          loop invariant PLACE_HOLDER_SUPPLEMENTARY_INVARIANTS;
          PLACE_HOLDER_LOOP
            */
            for (int i = 1; i <= num; i++) {
            catalan[i] = 0;
            
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= j <= i;
          loop invariant 0 <= i <= num;
          loop invariant catalan[i] == catalan_partial_sum(catalan, i, j);
          loop assigns j, catalan[i];
            */
            for (int j = 0; j < i; j++) {
                catalan[i] += catalan[j] * catalan[i - j - 1];
            }
            
        }
            
        return catalan[num];
}
