
/*@
  // No additional predicate or logic function is required for this program.
*/

int foo177(int num) {

    int result = 0;
    
    /* >>> LOOP INVARIANT TO FILL <<< */
    
    /*@
      loop invariant 2 <= j <= \at(num, Pre) + 1;
      loop invariant (j <= \at(num, Pre)) ==> (num >= 0);
      loop invariant (j <= \at(num, Pre)) ==> 
                    (((result == 0) && (num == \at(num, Pre))) || 
                     (result > 0 && \at(num, Pre) % result == 0 && result <= j));
      loop invariant (!(j <= \at(num, Pre))) ==> ((result == 0) && (num == \at(num, Pre)));
      loop assigns j, result, num;
    */
    for (int j = 2; j <= num; j++) {
        
        /* >>> LOOP INVARIANT TO FILL <<< */
        
        /*@
          loop invariant 2 <= j <= num + 1;
          loop invariant result == 0 || (num % result == 0 && result <= j);
          loop invariant num >= 0;
          loop assigns j, result, num;
        */
        while (num % j == 0) {
            result = j;
            num /= j;
        }
        
    }
            
    return result;
}
