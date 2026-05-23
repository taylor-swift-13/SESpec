
/*@
  assigns \nothing;
  ensures \result >= 0;
  ensures s < 1 ==> \result == 0;
*/
int foo315(int s) {
  int max = 0;

  if (s < 1) {
    return 0;
  }

  /*@
    loop invariant 1 <= l && l <= s + 1;
    loop invariant max >= 0;
    loop assigns l, max;
    loop variant s - l + 1;
  */
  for (int l = 1; l <= s; l++) {

    /*@
      loop invariant 1 <= b && b <= s - l + 2;
      loop invariant max >= 0;
      loop assigns b, max;
      loop variant s - l + 2 - b;
    */
    for (int b = 1; b <= s - l + 1; b++) {
      int h = s - l - b;
      int volume = l * b * h;
      if (volume > max) {
        max = volume;
      }
    }
  }

  return max;
}
