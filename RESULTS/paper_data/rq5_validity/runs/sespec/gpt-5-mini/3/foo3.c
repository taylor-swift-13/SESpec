
/*@ logic integer gcd_logic(integer a, integer b) =
    a <= 0 || b <= 0 ? 0
  : a == b ? a
  : a > b ? gcd_logic(a - b, b)
  : gcd_logic(a, b - a);
*/

/*@
  requires y1 >= 0;
  requires y2 >= 0;
  decreases \max(y1, y2);
  assigns \nothing;
  ensures \result == gcd_logic(y1, y2);
*/
int foo3(int y1, int y2);


int foo3(int y1, int y2) {

        if (y1 <= 0 || y2 <= 0) {
          return 0;
        }
        if (y1 == y2) {
          return y1;
        }
        if (y1 > y2) {
          return foo3(y1 - y2, y2);
        }
        return foo3(y1, y2 - y1);
}
