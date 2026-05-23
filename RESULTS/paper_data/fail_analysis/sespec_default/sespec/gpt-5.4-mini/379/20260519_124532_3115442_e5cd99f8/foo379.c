
/*@
  requires \true;
  assigns \nothing;
  
*/
int foo379(int l, int r) {

        int sum = 0;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant l == \at(l,Pre);
          loop invariant r == \at(r,Pre);
          loop assigns i, sum;
            */
            for (int i = l; i <= r; i++) {
            if (i % 2 == 0) {
                sum += i;
            }
        }
            
        return sum;
}
