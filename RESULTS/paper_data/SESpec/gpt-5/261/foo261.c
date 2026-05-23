
/*@
    requires a_len >= 0;
    requires a_len == 0 || \valid_read(a + (0 .. a_len-1));
    assigns \nothing;

    ensures a == \old(a);
    ensures a_len == \old(a_len);
    ensures x == \old(x);

    ensures 0 <= \result <= a_len;
    ensures (\result < a_len) ==> (a[\result] == \at(a[\result], Pre));

    ensures \result == \result;
*/
int foo261(int * a, int a_len, int x) {

        int i = 0;
        int j = a_len - 1;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant x == \at(x,Pre);
          loop invariant a_len == \at(a_len,Pre);
          loop invariant a == \at(a,Pre);

          loop invariant 0 <= i <= \at(a_len,Pre);
          loop invariant -1 <= j <= \at(a_len,Pre) - 1;

          loop invariant i <= j + 1;
          loop invariant (i <= j) ==> (0 <= i <= j < \at(a_len,Pre));
          loop invariant (i <= j) ==> (0 <= (i + j) / 2 < \at(a_len,Pre));

          loop invariant \forall integer k; 0 <= k < \at(a_len,Pre) ==> a[k] == \at(a[k], Pre);

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
