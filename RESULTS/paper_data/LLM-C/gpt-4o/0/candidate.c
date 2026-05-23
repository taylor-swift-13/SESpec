/*@
    requires m >= 0 && n >= 0;
    ensures \result >= 0;
    assigns \nothing;
    behavior base_case_m:
        assumes m == 0;
        ensures \result == n + 1;
    behavior base_case_n:
        assumes m > 0 && n == 0;
        ensures \result == ack(m - 1, 1);
    behavior recursive_case:
        assumes m > 0 && n > 0;
        ensures \result == ack(m - 1, ack(m, n - 1));
    complete behaviors base_case_m, base_case_n, recursive_case;
    disjoint behaviors base_case_m, base_case_n, recursive_case;
*/
int ack(int m, int n) {

    if (m == 0) {
      return n + 1;
    }
    if (n == 0) {
      return ack(m - 1, 1);
    }
    return ack(m - 1, ack(m, n - 1));
}
