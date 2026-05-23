/*@ 
  predicate Divides(integer d, integer x) = \exists integer k; x == k * d;

  predicate IsGcd(integer g, integer a, integer b) =
    g >= 0 &&
    Divides(g, a) && Divides(g, b) &&
    (\forall integer d; d >= 0 ==> (Divides(d, a) && Divides(d, b) ==> d <= g));
*/

int gcd(int y1, int y2);

/*@ 
  assigns \nothing;
  decreases (y1 > 0 && y2 > 0) ? (y1 + y2) : 0;

  behavior nonpos:
    assumes y1 <= 0 || y2 <= 0;
    ensures \result == 0;

  behavior pos:
    assumes y1 > 0 && y2 > 0;
    ensures IsGcd(\result, y1, y2);
    ensures \result >= 1;
    ensures \result <= y1 && \result <= y2;

  complete behaviors;
  disjoint behaviors;
*/
int gcd(int y1, int y2) {

        if (y1 <= 0 || y2 <= 0) {
          return 0;
        }
        if (y1 == y2) {
          return y1;
        }
        if (y1 > y2) {
          return gcd(y1 - y2, y2);
        }
        return gcd(y1, y2 - y1);
}
