
/*@ 
  assigns \nothing;
  ensures (\old(n) <= 0) ==> (\result == n);
  ensures (\old(n) > 0) ==> (\result == (n | \result));
*/
int foo224(int n) {

        int count = 0;
        int res = 0;
        int temp = n;
        
            
        /*@
          loop invariant (!(\at(n,Pre) > 0)) ==> ((temp == \at(n,Pre))&&(res == 0)&&(count == 0)&&(n == \at(n,Pre)));
          loop invariant n == \at(n,Pre);
          loop assigns res, temp, count;
            */
            while (temp > 0) {
            if (count % 2 == 1) {
                res |= (1 << count);
            }
            count++;
            temp >>= 1;
        }
            
        return (n | res);
}
