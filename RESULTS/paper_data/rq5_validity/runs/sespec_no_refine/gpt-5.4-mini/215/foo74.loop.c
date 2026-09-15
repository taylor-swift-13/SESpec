
/*@
  predicate temp_is_initial(integer temp, integer n0) = temp == n0;
*/

int foo74(int n) {

        int temp = n;
        
        /*@
          loop invariant (!(n != 0 && n % 3 == 0)) ==> ((temp == n)&&(n == n));
          loop invariant n == n;
          loop assigns temp;
        */
        while (temp != 0 && temp % 3 == 0) {
            temp /= 3;
        }
            
        return temp == 1;
}
