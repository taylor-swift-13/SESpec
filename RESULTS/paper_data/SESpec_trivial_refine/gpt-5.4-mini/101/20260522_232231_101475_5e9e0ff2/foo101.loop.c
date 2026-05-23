
/*@
  predicate valid_read_range{L}(int *p, integer l, integer u) =
    l <= u ==> \valid_read(p + (l .. u));
*/
/*@
  predicate valid_write_range{L}(int *p, integer l, integer u) =
    l <= u ==> \valid(p + (l .. u));
*/

/*@
  predicate in_bounds(integer x, integer l, integer u) = l <= x <= u;
*/
        
void foo101(int * b, int b_len, int iBegin, int iEnd, int * a, int a_len) {

        int k = iBegin;

        /*@
          loop invariant iBegin <= k <= iEnd;
          loop assigns a[..], k;
        */
        /*@
          loop invariant iBegin <= k <= iEnd;
          loop assigns a[..], k;
        */
            while (iEnd - k > 0) {
            a[k] = b[k];
            k = k + 1 ;
        }
            
}
