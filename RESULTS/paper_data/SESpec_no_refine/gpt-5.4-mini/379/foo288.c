
/*@
  assigns \nothing;
  ensures \result == sum_from(l, r) - sum_from(l + (((l & 1) == 0) ? 1 : 0), r) / 2;
*/
int foo288(int l, int r) {

        int sum = 0;
        
            
        /*@
          loop invariant r == \at(r,Pre);
          loop invariant l == \at(l,Pre);
          loop assigns i, sum;
            */
            for (int i = l; i <= r; i++) {
            if (i % 2 == 0) {
                sum += i;
            }
        }
            
        return sum;
}
