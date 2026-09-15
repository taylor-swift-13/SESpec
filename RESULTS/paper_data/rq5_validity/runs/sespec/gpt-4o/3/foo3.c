
/*@
  logic integer gcd(integer a, integer b) = 
    (b == 0) ? a : gcd(b, a % b);
*/

/*@
  requires y1 > 0;
  requires y2 > 0;
  assigns \nothing;
*/
int foo3(int y1, int y2);

/*@
  requires y1 > 0;
  requires y2 > 0;
  decreases y1 + y2;
  assigns \nothing;
  ensures \result > 0;
  ensures \result <= y1 && \result <= y2;
*/
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
