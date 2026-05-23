
        /*@
        PLACE_HOLDER_PREDICATE_OR_LOGIC_FUNCTION
        */
        
/*@
        PLACE_HOLDER_PREDICATE_OR_LOGIC_FUNCTION
        */
        

int foo128(int s) {

        int foo128 = 0;

        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant (l <= \at(s,Pre)) ==> (((foo128 == 0)&&(s == \at(s,Pre))) || (foo128 >= 0));
          loop invariant (!(l <= \at(s,Pre))) ==> ((foo128 == 0)&&(s == \at(s,Pre)));
          loop invariant s == \at(s,Pre);
          loop assigns l, b, h, volume, foo128;
            */
            for (int l = 1; l <= s; l++) {
            
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
              loop invariant 1 <= l <= s + 1;
              loop invariant foo128 >= 0;
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
