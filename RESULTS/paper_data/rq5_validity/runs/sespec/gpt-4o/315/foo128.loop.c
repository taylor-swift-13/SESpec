
/*@
  // No additional predicate or logic function is needed for this program.
*/

int foo128(int s) {

    int foo128 = 0;

    /*@
      loop invariant 1 <= l <= s + 1;
      loop invariant foo128 >= 0;
      loop invariant s == \at(s, Pre);
      loop assigns l, b, h, volume, foo128;
    */
    for (int l = 1; l <= s; l++) {
        
        /*@
          loop invariant 1 <= b <= s - l + 2;
          loop invariant foo128 >= 0;
          loop invariant s == \at(s, Pre);
          loop invariant l >= 1 && l <= s;
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
