
/*@
  // Logic function to count the number of integers in [l, u] not divisible by code
  logic integer count_non_divisible(integer l, integer u, integer code) =
    (l > u) ? 0 : ((l % code != 0 ? 1 : 0) + count_non_divisible(l + 1, u, code));
*/

/*@
  requires code > 0; // code must be positive
  requires l <= m;   // valid range [l, m]
  requires b >= 0;   // b must be non-negative
  assigns \nothing;  // no global state is modified
  
  ensures \result != -1 ==> l <= \result <= m; // result is within range if not -1
*/
int foo344(int code, int b, int l, int m) {

    int ret = 0;

    /*@
      loop invariant m == \at(m,Pre); // m is unchanged
      loop invariant l == \at(l,Pre); // l is unchanged
      loop invariant b == \at(b,Pre); // b is unchanged
      loop invariant code == \at(code,Pre); // code is unchanged
      loop invariant l <= c <= m + 1; // c is within range
      loop invariant 0 <= ret; // ret is non-negative
      loop assigns c, ret; // loop modifies c and ret
      loop variant m - c; // loop progresses toward termination
    */
    for (int c = l; c <= m; c++) {
        if (c % code != 0) {
            ret++;
        }
        if (ret == b) {
            return c;
        }
    }

    return -1;
}
