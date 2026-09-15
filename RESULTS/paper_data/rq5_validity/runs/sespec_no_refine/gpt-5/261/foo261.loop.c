
/*@
  // No additional predicates or logic functions are required for this loop.
*/

int foo261(int * a, int a_len, int x) {

        int i = 0;
        int j = a_len - 1;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
              loop invariant -1 <= j < a_len;
              loop invariant 0 <= i <= j + 1;
              loop invariant a_len == \at(a_len,Pre);
              loop invariant x == \at(x,Pre);
              loop invariant a == \at(a,Pre);
              loop assigns i, j;
            */
            while (i <= j) {
            int mid = (i + j) / 2;
            if (a[mid] == x) {
                return mid;
            } else if (a[mid] < x) {
                i = mid + 1;
            } else {
                j = mid - 1;
            }
        }
            
        return i;
}
