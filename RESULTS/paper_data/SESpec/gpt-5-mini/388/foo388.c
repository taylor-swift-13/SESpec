
/*@
  requires c != 0; // division by zero must be prevented by caller

  assigns \nothing;
  ensures \at(r,Pre) <= 0 ==> r == \at(r,Pre) && num == \at(num,Pre);
*/
int foo388(int num, int c, int r) {

    int result = 0;

    /*@
      // r never increases: it's at most its initial value
      loop invariant r <= \at(r,Pre);

      // number of iterations performed so far is non-negative
      loop invariant (\at(r,Pre) - r) >= 0;

      // while no iteration has occurred, locals equal their pre-state values
      loop invariant (\at(r,Pre) - r == 0) ==> (result == 0 && num == \at(num,Pre));

      // c is preserved
      loop invariant c == \at(c,Pre);

      // r is always an integer (and non-increasing); additionally r >= 0 while loop condition holds,
      // but we do not assert unconditional non-negativity at entry since pre-state may not guarantee it.
      loop invariant r >= 0 || r <= \at(r,Pre);

      loop assigns r, num, result;
    */
    while (r > 0) {
        r -= 1;
        num *= 10;
        result = num / c;
        num %= c;
    }

    return result;
}
