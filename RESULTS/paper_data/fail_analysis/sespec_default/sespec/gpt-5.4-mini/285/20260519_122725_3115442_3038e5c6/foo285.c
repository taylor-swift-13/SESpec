
/*@ 
  assigns \nothing;
*/
const char * foo285(int n) {

        int count = 0;
        
        /*@
          loop invariant n == \at(n,Pre);
          loop invariant 0 <= count <= i;
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
