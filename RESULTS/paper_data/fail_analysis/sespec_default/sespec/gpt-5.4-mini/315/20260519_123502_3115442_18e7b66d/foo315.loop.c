
        /*@
        PLACE_HOLDER_PREDICATE_OR_LOGIC_FUNCTION
        */
        
/*@
        PLACE_HOLDER_PREDICATE_OR_LOGIC_FUNCTION
        */
        

int foo315(int s) {

        int foo315 = 0;

        /*@
          loop invariant 0 <= l <= s + 1;
          loop invariant foo315 >= 0;
          loop assigns l, foo315;
          loop variant s - l + 1;
        */
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant (l <= \at(s,Pre)) ==> (foo315 >= 0);
          loop invariant (l <= \at(s,Pre)) ==> (((foo315 == 0)&&(s == \at(s,Pre))) || (foo315 >= 0));
          loop invariant (!(l <= \at(s,Pre))) ==> ((foo315 == 0)&&(s == \at(s,Pre)));
          loop invariant s == \at(s,Pre);
          loop assigns l, b, h, volume, foo315;
            */
            for (int l = 1; l <= s; l++) {
            
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 1 <= b <= s - l + 2;
          loop invariant foo315 >= 0;
          loop assigns b, h, volume, foo315;
          loop variant s - l + 2 - b;
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
