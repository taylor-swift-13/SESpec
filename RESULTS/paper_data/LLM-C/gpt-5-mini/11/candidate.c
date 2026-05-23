int recursion(int i);

/*@
    behavior neg:
        assumes i < 0;
        ensures \result == 0;
        assigns \nothing;

    behavior zero:
        assumes i == 0;
        ensures \result == 1;
        assigns \nothing;

    behavior pos:
        assumes i > 0;
        ensures \result == 1;
        assigns \nothing;

    complete behaviors neg, zero, pos;
    disjoint behaviors neg, zero, pos;

    decreases (i >= 0 ? i : 0);
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
