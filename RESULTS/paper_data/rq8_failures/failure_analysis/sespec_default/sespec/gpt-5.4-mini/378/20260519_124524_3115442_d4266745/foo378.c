
/*@
  
  assigns \nothing;
*/
int foo378(int l, int r) {

        int sum = 0;
        
            
        /*@
          loop invariant l <= i;
          loop invariant r == \at(r,Pre);
          loop invariant l == \at(l,Pre);
          loop assigns i, sum;
        */
            for (int i = l; i <= r; i++) {
            if (i % 2 != 0) {
                sum += i;
            }
        }
            
        return sum;
}
