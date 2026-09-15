
/*@
  assigns \nothing;
  ensures \result == div_count_upto(n, n);
*/
int foo383(int n) {

        int count = 0;
        
        /*@
          loop invariant 1 <= i <= n + 1 || n < 1;
          loop invariant n == \at(n,Pre);
          loop invariant count >= 0;
          loop invariant (i <= \at(n,Pre)) ==> (((i >= 1) && (count == div_count_upto(n, i - 1))) || (i < 1));
          loop invariant n == \at(n,Pre);
          loop assigns i, count;
        */
        for (int i = 1; i <= n; i++) {
            if (n % i == 0) {
                count++;
            }
        }
            
        return count;
}
