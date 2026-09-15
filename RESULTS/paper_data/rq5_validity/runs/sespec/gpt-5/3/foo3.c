
/*@ 
  requires y1 > 0;
  requires y2 > 0;
  assigns \nothing;
*/
int foo3(int y1, int y2);

/*@ logic integer gcd_rec(integer a, integer b) =
      a <= 0 || b <= 0 ? 0 :
      a == b ? a :
      a > b ? gcd_rec(a - b, b) : gcd_rec(a, b - a); */

/*@
  requires y1 > 0;
  requires y2 > 0;
  decreases y1 + y2;
  assigns \nothing;
  ensures \result == gcd_rec(y1, y2);
  ensures \result > 0;
  ensures \result <= y1 && \result <= y2;
  ensures y1 == y2 ==> \result == y1;
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
