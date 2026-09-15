int countNo(int a, int n, int l, int r);

/*@ 
  logic integer count_non_multiples(integer a, integer l, integer r) =
    l > r ? 0 : ((l % a != 0) ? 1 : 0) + count_non_multiples(a, l + 1, r);
*/

/*@
  requires a != 0;
  requires n >= 1;

  assigns \nothing;

  ensures \result == -1 ==> count_non_multiples(a, l, r) < n;
  ensures \result != -1 ==> l <= \result <= r 
                            && count_non_multiples(a, l, \result) == n
                            && (\forall integer i; l <= i < \result ==> count_non_multiples(a, l, i) < n);
*/
int countNo(int a, int n, int l, int r) {

        int count = 0;
        /*@
          loop invariant l <= i <= r + 1;
          loop invariant 0 <= count <= (i - l);
          loop invariant count == count_non_multiples(a, l, i - 1);
          loop assigns i, count;
          loop variant r - i + 1;
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
