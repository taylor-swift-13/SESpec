int gcd(int y1, int y2);

/*@
    assigns \nothing;
    behavior non_positive:
        assumes y1 <= 0 || y2 <= 0;
        ensures \result == 0;
    behavior positive:
        assumes y1 > 0 && y2 > 0;
        ensures \result > 0;
        ensures y1 % \result == 0 && y2 % \result == 0;
        ensures \forall integer d; (d > 0 && y1 % d == 0 && y2 % d == 0) ==> d <= \result;
        ensures \result <= y1 && \result <= y2;
        decreases y1 + y2;
    complete behaviors non_positive, positive;
    disjoint behaviors non_positive, positive;
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
