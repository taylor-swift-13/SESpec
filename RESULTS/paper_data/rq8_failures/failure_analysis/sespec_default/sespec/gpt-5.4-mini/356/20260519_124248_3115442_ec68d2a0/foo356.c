
/*@ 
  assigns \nothing;
  
*/
int foo356(int n) {

        int res = 0;
        int count = 0;
        int temp = n;
        
            
        /*@
          loop invariant count >= 0;
          loop invariant n == \at(n,Pre);
          loop invariant temp == n - count || temp <= n;
          loop invariant count == 0 ==> res == 0;
          loop assigns res, temp, count;
            */
            while (temp > 0) {
            if (count % 2 == 0) {
                res = res | (1 << count);
            }
            count++;
            temp >>= 1;
        }
            
        return n ^ res;
}
