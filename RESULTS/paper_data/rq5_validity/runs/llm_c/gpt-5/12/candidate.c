int recursion(int i);

/*@ 
  assigns \nothing;

  behavior nonneg:
    assumes i >= 0;
    ensures \result == 1;

  behavior neg:
    assumes i < 0;
    ensures \result == 0;

  complete behaviors nonneg, neg;
  disjoint behaviors nonneg, neg;

  ensures \result == (i >= 0 ? 1 : 0);
  ensures \result == 0 || \result == 1;

  decreases i >= 0 ? i : 0;
*/
int recursion(int i) {

    if (i == 0) {
      return 1;
    }
    if (i > 0) {
      return recursion(i - 1);
    }
    if (i < 0) {
      return 0;
    }
    return 1;
}
