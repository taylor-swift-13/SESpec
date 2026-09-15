
/*@ logic boolean power_of_4(integer x) =
      x == 1 ? \true :
      (x > 1 && x % 4 == 0 ? power_of_4(x / 4) : \false);
*/
/*@
  requires \true;
  assigns \nothing;
  ensures \old(n) <= 0 ==> \result == 0;
  ensures \old(n) > 0  ==> (\result == 0 || \result == 1);
  ensures \old(n) > 0  && \result == 1 ==> \old(n) >= 1;
*/
int foo146(int n) {

        if(n <= 0) {
            return 0;
        }
        
        /*@
          loop invariant n > 0;
          loop invariant (n % 4 == 0) ==> (n >= 4);
          loop invariant (!(n % 4 == 0)) ==> (n % 4 != 0);
          loop assigns n;
        */
        while (n % 4 == 0) {
            n /= 4;
        }
            
        return n == 1;
}
