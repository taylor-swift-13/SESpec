
/*@
  // No additional predicate or logic function is needed for this program.
*/

int foo128(int s) {

    int foo128 = 0;

    /*@
      loop invariant 1 <= l <= s + 1;
      loop invariant foo128 >= 0;
      loop invariant s == \at(s,Pre);
      loop invariant (l <= \at(s,Pre)) ==> (((foo128 == 0)&&(s == \at(s,Pre))) || (\exists integer l0, b0, h0; 1 <= l0 <= l && 1 <= b0 <= s - l0 + 1 && h0 == s - l0 - b0 && foo128 == l0 * b0 * h0));
      loop invariant (!(l <= \at(s,Pre))) ==> ((foo128 == 0)&&(s == \at(s,Pre)));
      loop assigns l, b, h, volume, foo128;
    */
    for (int l = 1; l <= s; l++) {
        
        /*@
          loop invariant 1 <= b <= s - l + 2;
          loop invariant foo128 >= 0;
          loop invariant s == \at(s,Pre);
          loop invariant (\exists integer l0, b0, h0; 1 <= l0 <= l && 1 <= b0 < b && h0 == s - l0 - b0 && foo128 == l0 * b0 * h0);
          loop assigns b, h, volume, foo128;
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
