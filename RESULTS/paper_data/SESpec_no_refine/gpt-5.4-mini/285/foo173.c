
/*@ 
  ensures \result == (divcount(n, 1, 0) % 2 == 0 ? "Even" : "Odd");
  assigns \nothing;
*/
const char * foo173(int n) {

        int count = 0;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant n == \at(n,Pre);
          loop assigns i, count;
            */
            for (int i = 1; i <= n; i++) {
            if (n % i == 0) {
                count++;
            }
        }
            
        if (count % 2 == 0) {
            return "Even";
        } else {
            return "Odd";
        }
}
