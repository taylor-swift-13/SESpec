
        /*@
        requires 0 <= leftElement <= rightElement < a_len;
        requires \valid_read(a + (0 .. a_len-1));
        */
        
int foo298(int * a, int a_len, int leftElement, int rightElement) {

        int i = leftElement;
        int j = rightElement;
        
            
        /*@
          loop invariant leftElement <= i <= j + 1;
          loop invariant -1 <= j < a_len;
          loop invariant 0 <= i <= a_len;
          loop assigns i, j;
        */
            while (i <= j) {
            int mid = (i + j) / 2;
            if (a[mid] == mid) {
                i = mid + 1;
            } else {
                j = mid - 1;
            }
        }
            
        return i;
}
