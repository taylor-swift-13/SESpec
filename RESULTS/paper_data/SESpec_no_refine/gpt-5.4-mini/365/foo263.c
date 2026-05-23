
/*@
  assigns \nothing;
  ensures \result == (odd_count(n) == 0 ? 0 : odd_sum(n) / odd_count(n));
*/
int foo263(int n) {

        int sum = 0;
        int count = 0;
        
            
        /*@
          loop invariant n == \at(n,Pre);
          loop invariant 0 <= count <= i - 1;
          loop invariant sum == odd_sum(i - 1);
          loop invariant count == odd_count(i - 1);
          loop assigns i, sum, count;
            */
            for (int i = 1; i <= n; i++) {
            if (i % 2 != 0) {
                sum += i;
                count++;
            }
        }
            
        return sum / count;
}
