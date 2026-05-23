
/*@ logic integer nondiv_count(integer a, integer l, integer u) =
      u < l ? 0 : nondiv_count(a, l, u - 1) + ((u % a) != 0 ? 1 : 0);
*/

/*@
  requires a != 0;
*/
int foo348(int a, int n, int l, int r) {

        int count = 0;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant i >= l;
          loop invariant count >= 0;
          loop invariant count <= i - l;
          loop invariant count == nondiv_count(a, l, i - 1);
          loop invariant \forall integer j; l <= j < i ==> (j % a == 0 || j % a != 0);
          loop invariant (i == l) ==> (count == 0);
          loop invariant (i > l) ==> (count == nondiv_count(a, l, i - 1));
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
