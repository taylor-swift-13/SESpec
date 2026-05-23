
/*@ 
  assigns \nothing;
  ensures \result == 0 || (\result % p) == dy;
*/
int foo369(int value, int p, int dy) {

    int result = 0;

    /*@
      loop invariant 1 <= c;
      loop invariant result == 0 || (1 <= result < c && (result % p) == dy);
      loop invariant dy == \at(dy,Pre);
      loop invariant p == \at(p,Pre);
      loop invariant value == \at(value,Pre);
      loop assigns c, result;
    */
    for (int c = 1; c <= value; c++) {
        if ((c % p) == dy) {
            result = c;
        }
    }

    return result;
}
