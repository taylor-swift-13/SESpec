
/*@ 
  logic integer max(integer a, integer b) = (a > b) ? a : b;

  logic integer compute_max_volume(integer s) = 
    \max(1, s, 
         \lambda integer l; 
           \max(1, s - l + 1, 
                \lambda integer b; l * b * (s - l - b)));
*/

/*@ 
  requires s >= 0;
  assigns \nothing;
  ensures \result >= 0;
*/
int foo128(int s) {

    int foo128 = 0;

    /*@
      loop invariant 1 <= l <= s + 1;
      loop invariant foo128 >= 0;
      loop invariant s == \at(s, Pre);
      loop assigns foo128;
    */
    for (int l = 1; l <= s; l++) {
        
        /*@
          loop invariant 1 <= b <= s - l + 2;
          loop invariant foo128 >= 0;
          loop invariant s == \at(s, Pre);
          loop invariant l >= 1 && l <= s;
          loop assigns foo128;
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
