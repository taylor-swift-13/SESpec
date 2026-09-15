
        /*@
        requires a_len >= 0;
        requires \valid_read(a + (0 .. a_len-1));
        */
        
int foo261(int * a, int a_len, int x) {

        int i = 0;
        int j = a_len - 1;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= i <= a_len;
          loop invariant -1 <= j < a_len;
          loop invariant i <= j + 1;
          loop assigns mid, i, j;
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
