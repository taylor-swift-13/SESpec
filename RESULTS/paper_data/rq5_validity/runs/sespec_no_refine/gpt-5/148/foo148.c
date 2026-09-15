
/*@ logic boolean pow2_pos(integer x) =
      x == 1 ? \true : (x > 1 && x % 2 == 0 && pow2_pos(x/2)); */
/*@ logic boolean is_power_of_two(integer x) =
      x > 0 && pow2_pos(x); */
/*@
  assigns \nothing;
  ensures \old(n) <= 0 ==> \result == 0;
*/
int foo148(int n) {

        if(n <= 0) {
            return 0;
        }
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant n > 0;
          loop assigns n;
            */
            while (n % 2 == 0) {
            n /= 2;
        }
            
        return n == 1;
}
