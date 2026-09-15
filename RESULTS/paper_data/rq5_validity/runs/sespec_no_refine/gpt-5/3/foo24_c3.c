int foo24_c3(int y1, int y2);


/*@ logic integer max_int(integer a, integer b) = a >= b ? a : b; */
/*@ logic integer gcd_nonneg(integer a, integer b) =
      (a == 0 || b == 0) ? (a + b)
    : (a == b) ? a
    : (a > b) ? gcd_nonneg(a - b, b)
              : gcd_nonneg(a, b - a); */
/*@ logic integer foo24_c3_res(integer y1, integer y2) =
      (y1 <= 0 || y2 <= 0) ? 0 : gcd_nonneg(y1, y2); */
/*@
  requires \true;
  decreases (y1 <= 0 || y2 <= 0) ? 0 : max_int(y1, y2);
  assigns \nothing;
  ensures \result == foo24_c3_res(y1, y2);
  ensures \result >= 0;
*/
int foo24_c3(int y1, int y2) {

        if (y1 <= 0 || y2 <= 0) {
          return 0;
        }
        if (y1 == y2) {
          return y1;
        }
        if (y1 > y2) {
          return foo24_c3(y1 - y2, y2);
        }
        return foo24_c3(y1, y2 - y1);
}