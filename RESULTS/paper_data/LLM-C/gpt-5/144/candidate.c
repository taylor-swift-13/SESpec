int passPillow(int n, int time);

/*@ 
  requires n >= 2;
  requires time >= 0;
  assigns \nothing;
  ensures 1 <= \result <= n;

  behavior lt:
    assumes 2 * (\old(time) % (n - 1)) < n;
    ensures \result == 2 * (\old(time) % (n - 1)) + 1;

  behavior ge:
    assumes 2 * (\old(time) % (n - 1)) >= n;
    ensures \result == 2 * n - (2 * (\old(time) % (n - 1))) - 1;

  complete behaviors lt, ge;
  disjoint behaviors lt, ge;
*/
int passPillow(int n, int time) {

        time = time % (n - 1) * 2;
        /*@ assert 0 <= time && time <= 2 * (n - 2); */

        if (time < n) {
            /*@ assert 1 <= time + 1 && time + 1 <= n; */
            return time + 1;
        }
        /*@ assert time >= n && time <= 2 * (n - 2); */
        /*@ assert 1 <= 2 * n - time - 1 && 2 * n - time - 1 <= n; */
        return n * 2 - time - 1;
}
