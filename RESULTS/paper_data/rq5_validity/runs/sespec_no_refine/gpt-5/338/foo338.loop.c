
/*@
*/

        
/*@
  requires num >= 0;
  ensures \result == 0 || (\exists integer k; 2 <= k <= num && k == \result);
*/


int foo338(int num) {

    int result = 0;
    
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant result == 0 || (2 <= result && result <= j);
          loop invariant num >= 0;
          loop assigns j, result, num;
            */
            for (int j = 2; j <= num; j++) {

        /* >>> LOOP INVARIANT TO FILL <<< */

        /*@
          loop invariant j >= 2;
          loop invariant num >= 0;
          loop invariant result == 0 || (2 <= result <= j);
          loop invariant \exists integer a,b; a >= 0 && b >= 0 && num == a * j + b && 0 <= b < j;
          loop assigns num, result;
        */
        while (num % j == 0) {
            result = j;
            num /= j;
        }

    }
            
    return result;
}
