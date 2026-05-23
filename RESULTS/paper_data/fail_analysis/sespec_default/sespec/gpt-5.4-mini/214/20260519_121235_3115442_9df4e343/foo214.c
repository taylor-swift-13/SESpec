
/*@
PLACE_HOLDER_PREDICATE_OR_LOGIC_FUNCTION
*/
        

/*@
PLACE_HOLDER_PREDICATE_OR_LOGIC_FUNCTION
*/


int foo214(int num) {

        int *catalan = (int *)malloc(sizeof(int) * (num + 1));
        int catalan_len = num + 1;
        catalan[0] = 1;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop assigns i, catalan[0..num];
            */
            for (int i = 1; i <= num; i++) {
            catalan[i] = 0;
            
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
              loop assigns j, catalan[i];
              loop variant i - j;
            */
            for (int j = 0; j < i; j++) {
                catalan[i] += catalan[j] * catalan[i - j - 1];
            }
            
        }
            
        return catalan[num];
}
