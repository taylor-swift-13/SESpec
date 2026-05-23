/*@
    requires i >= 0;
    assigns \nothing;
    ensures \result == 1;
    decreases i;
*/
int recursion(int i);

 /*@
    requires i >= 0;
    assigns \nothing;
    ensures \result == 1;
    decreases i;
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
