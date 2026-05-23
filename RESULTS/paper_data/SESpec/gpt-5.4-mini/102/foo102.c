
/*@
  assigns \nothing;
  ensures \old(num) < 0 ==> \result == \old(num);
  ensures \old(num) >= 0 && \old(num) < 10 ==> \result == \old(num);
  ensures \old(num) >= 10 ==> \result >= 0 && \result < 10;
*/
int foo102(int num) {

        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant num >= 0 || \at(num,Pre) < 0;
          loop invariant (\at(num,Pre) < 10) ==> (num == \at(num,Pre));
          loop invariant (\at(num,Pre) >= 10) ==> (num >= 0);
          loop assigns num;
            */
            while (num >= 10) {
            int sum = 0;
            
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant num >= 0;
          loop invariant sum >= 0;
          loop assigns num, sum;
            */
            while (num > 0) {
                sum += num % 10;
                num /= 10;
            }
            
            num = sum;
        }
            
        return num;
}
