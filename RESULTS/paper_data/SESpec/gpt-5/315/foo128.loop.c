
/*@
  logic integer max_volume(integer s, integer l) =
    l <= 1 ? 0 :
    (s - l + 1) <= 1 ? 0 :
    ((l * 1 * (s - l - 1)) > max_volume(s, l - 1) ?
       (l * 1 * (s - l - 1)) : max_volume(s, l - 1));
*/

/*@
        predicate dummy_predicate{L}(integer x) = \true;
        */
        

int foo128(int s) {

        int foo128 = 0;

        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant s == \at(s,Pre);
          loop invariant foo128 >= 0;
          loop assigns l, foo128;
            */
            for (int l = 1; l <= s; l++) {
            
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 1 <= l <= s + 1 ==> \true;
          loop invariant foo128 >= 0;
          loop invariant s == \at(s,Pre);
          loop invariant 1 <= b <= s - l + 2;
          loop assigns foo128, b;
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
