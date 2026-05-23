
/*@
predicate PLACE_HOLDER_PREDICATE_OR_LOGIC_FUNCTION;
*/

int foo380(int number) {

        int sum = 0;
        
        /*@
          loop invariant number == \at(number,Pre);
          loop assigns i, sum;
            */
            for (int i = 1; i <= number / 2; i++) {
            if (number % i == 0) {
                sum += i;
            }
        }
            
        return sum;
}
