/*@
    decreases i > 0 ? i : 0;
    ensures i == 0 ==> \result == 1;
    ensures i > 0 ==> \result == 1;
    ensures i < 0 ==> \result == 0;
*/
int recursion(int i);

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
