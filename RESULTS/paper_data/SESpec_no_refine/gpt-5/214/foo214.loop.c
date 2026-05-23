
/*@
  predicate PLACE_HOLDER_PREDICATE_OR_LOGIC_FUNCTION == \true;
*/


/*@
  predicate PLACE_HOLDER_PREDICATE_OR_LOGIC_FUNCTION == \true;
*/


int foo214(int num) {

        int *catalan = (int *)malloc(sizeof(int) * (num + 1));
        int catalan_len = num + 1;
        catalan[0] = 1;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 1 <= i <= num + 1;
          loop invariant catalan[0] == 1;
          loop invariant \forall integer k; 1 <= k < i ==> catalan[k] >= 0;
          loop invariant \forall integer k; i <= k <= num ==> \true;
          loop assigns i, catalan[..], j;
            */
            for (int i = 1; i <= num; i++) {
            catalan[i] = 0;
            
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
              loop invariant 1 <= i <= num;
              loop invariant 0 <= j <= i;
              loop invariant \forall integer k; 0 <= k < i ==> catalan[k] == \at(catalan[k],Pre);
              loop invariant catalan[i] == \sum(integer t=0, j-1) (\at(catalan[t],Pre) * \at(catalan[i - t - 1],Pre));
              loop assigns catalan[i], j;
            */
            for (int j = 0; j < i; j++) {
                catalan[i] += catalan[j] * catalan[i - j - 1];
            }
            
        }
            
        return catalan[num];
}
