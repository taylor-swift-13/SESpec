
/*@
predicate NonNegative(int x) = x >= 0;
*/

/*@
  requires \true;
  assigns \nothing;
  ensures \result >= 0;
  ensures \result == max_volume_upto(\at(s,Pre)+1, \at(s,Pre));
*/
int foo128(int s) {

        int foo128 = 0;

        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant (l <= \at(s,Pre)) ==> (((foo128 == 0)&&(s == \at(s,Pre))) || (foo128 >= 0 && foo128 == max_volume_upto(l, s)));
          loop invariant (!(l <= \at(s,Pre))) ==> ((foo128 == 0)&&(s == \at(s,Pre)));
          loop invariant s == \at(s,Pre);
          loop assigns l, b, h, volume, foo128;
            */
            for (int l = 1; l <= s; l++) {
            
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
            loop invariant 1 <= l <= s+1;
            loop invariant foo128 >= 0;
            loop invariant (\forall int l0; 1 <= l0 < l ==> 
                              (\exists int b0,h0; 1 <= b0 <= s - l0 + 1 && h0 == s - l0 - b0 && foo128 >= l0*b0*h0));
            loop assigns l, foo128;
            */
            for (int b = 1; b <= s - l + 1; b++) {
                int h = s - l - b;
                int volume = l * b * h;
                if (volume > foo128) {
                    foo128 = volume;
                }
            }
            
        }
        return foo128;
}
