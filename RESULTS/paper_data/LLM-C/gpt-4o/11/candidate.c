/*@
    requires \true;
    ensures \result == 1 ==> i >= 0;
    ensures \result == 0 ==> i < 0;
    assigns \nothing;
    behavior base_case:
        assumes i == 0;
        ensures \result == 1;
    behavior positive_case:
        assumes i > 0;
        ensures \result == 1;
    behavior negative_case:
        assumes i < 0;
        ensures \result == 0;
    complete behaviors base_case, positive_case, negative_case;
    disjoint behaviors base_case, positive_case, negative_case;
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
