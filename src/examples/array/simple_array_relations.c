// Per-element array relations expressed DIRECTLY with `\forall` — no
// custom `predicate` / `logic` helper required. `\at(e, Pre)` may appear
// inside a `loop invariant` directly (NOT inside a predicate body).

/*@
  requires n >= 1;
  requires \valid_read(a + (0..n-1));
  ensures \forall integer k; 0 <= k < n ==> a[k] <= \result;
  ensures \forall integer k; 0 <= k < n ==> a[k] == \at(a[k], Pre);
  assigns \nothing;
*/
int find_max(int *a, int n) {
    int m = a[0];
    int i = 1;
    /*@
      loop invariant 1 <= i <= n;
      loop invariant \forall integer k; 0 <= k < i ==> a[k] <= m;
      loop invariant \forall integer k; 0 <= k < n ==> a[k] == \at(a[k], Pre);
      loop assigns i, m;
      loop variant n - i;
    */
    while (i < n) {
        if (a[i] > m) m = a[i];
        i++;
    }
    return m;
}
