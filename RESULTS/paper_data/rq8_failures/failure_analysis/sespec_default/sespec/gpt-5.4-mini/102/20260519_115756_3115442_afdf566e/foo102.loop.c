
/*@
PLACE_HOLDER_PREDICATE_OR_LOGIC_FUNCTION
*/
        
/*@
PLACE_HOLDER_PREDICATE_OR_LOGIC_FUNCTION
*/
        

int foo102(int num) {

        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant (\at(num,Pre) >= 10) ==> (num >= 0);
          loop invariant (\at(num,Pre) >= 10) ==> (((num == \at(num,Pre))) || (num >= 0));
          loop invariant (!(\at(num,Pre) >= 10)) ==> ((num == \at(num,Pre)));
          loop assigns num;
            */
            while (num >= 10) {
            int sum = 0;
            
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
            loop invariant sum >= 0;
            loop invariant num >= 0;
            loop assigns sum, num;
            */
            while (num > 0) {
                sum += num % 10;
                num /= 10;
            }
            
            num = sum;
        }
            
        return num;
}
