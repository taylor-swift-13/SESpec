
/*@
logic integer max2(integer a, integer b) = (a > b) ? a : b;
*/

int foo315(int s) {

        int foo315 = 0;

        /*@
          loop invariant l >= 1;
          loop invariant foo315 >= 0;
          loop assigns l, foo315;
        */
        for (int l = 1; l <= s; l++) {
            
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant b >= 1;
          loop invariant foo315 >= 0;
          loop assigns b, foo315;
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
