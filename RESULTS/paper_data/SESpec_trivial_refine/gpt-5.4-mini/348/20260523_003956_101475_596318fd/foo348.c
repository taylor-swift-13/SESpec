
/*@ logic integer foo348_count_nondiv(integer a, integer l, integer u) =
      u < l ? 0 : foo348_count_nondiv(a, l, u - 1) + ((u % a != 0) ? 1 : 0); */
/*@ 
  requires a != 0;
  requires n > 0;
  requires l <= r + 1;
  assigns \nothing;
  ensures \result != -1 ==> l <= \result <= r;
  ensures \result != -1 ==> foo348_count_nondiv(a, l, \result) == n;
  ensures \result != -1 ==> \result % a != 0;
*/
int foo348(int a, int n, int l, int r) {

        int count = 0;

        /*@
          loop invariant l <= i;
          loop invariant i <= r + 1;
          loop invariant count == foo348_count_nondiv(a, l, i - 1);
          loop invariant 0 <= count < n;
          loop assigns i, count;
        */
        for (int i = l; i <= r; i++) {
            if (i % a != 0) {
                count++;
            }
            if (count == n) {
                return i;
            }
        }

        return -1;
}
