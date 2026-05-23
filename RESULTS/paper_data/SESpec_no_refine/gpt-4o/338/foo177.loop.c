
/*@
  // No additional predicate or logic function is required for this program
*/

int foo177(int num) {

    int result = 0;
    
    /*@
      loop invariant 2 <= j <= \at(num, Pre) + 1;
      loop invariant (j <= \at(num, Pre)) ==> (num >= 0);
      loop invariant (j <= \at(num, Pre)) ==> ((result == 0 && num == \at(num, Pre)) || (result > 0 && \at(num, Pre) % result == 0 && result <= \at(num, Pre)));
      loop invariant (!(j <= \at(num, Pre))) ==> (result == 0 && num == \at(num, Pre));
      loop assigns j, result, num;
    */
    for (int j = 2; j <= num; j++) {
        
        /*@
          loop invariant 2 <= j <= num + 1;
          loop invariant result == 0 || (num % result == 0 && result <= num);
          loop invariant num >= 0;
          loop assigns result, num;
        */
        while (num % j == 0) {
            result = j;
            num /= j;
        }
        
    }
            
    return result;
}
