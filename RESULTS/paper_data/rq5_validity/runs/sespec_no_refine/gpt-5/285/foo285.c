
/*@
  assigns \nothing;
  ensures (\result == "Even") <==> (div_count(n, n) % 2 == 0);
  ensures (\result == "Odd")  <==> (div_count(n, n) % 2 != 0);
*/
const char * foo285(int n) {

        int count = 0;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= count <= i - 1;
          loop invariant count == div_count(n, i - 1);
          loop invariant (i <= \at(n,Pre)) ==> (count == div_count(n, i - 1)) ;
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
