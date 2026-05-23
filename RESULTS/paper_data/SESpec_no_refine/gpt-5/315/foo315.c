
/*@
*/
        
/*@
  assigns \nothing;
  ensures \result == 0;
*/
int foo315(int s) {

        int foo315 = 0;

        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 1 <= l <= s + 1;
          loop invariant s == \at(s,Pre);
          loop invariant foo315 >= 0;
          loop assigns l, b, h, volume, foo315;
            */
            for (int l = 1; l <= s; l++) {
            
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 1 <= l <= s + 1;
          loop invariant foo315 >= 0;
          loop invariant foo315 >= 0;
          loop assigns foo315;
            */
            for (int b = 1; b <= s - l + 1; b++) {
                int h = s - l - b;
                int volume = l * b * h;
                if (volume > foo315) {
                    foo315 = volume;
                }
            }
            
        }
            
        return foo315;
}
