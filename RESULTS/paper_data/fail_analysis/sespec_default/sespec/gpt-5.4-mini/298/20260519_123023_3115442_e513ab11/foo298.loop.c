
int foo298(int * a, int a_len, int leftElement, int rightElement) {

        int i = leftElement;
        int j = rightElement;
        
        /*@
          loop invariant leftElement == \at(leftElement,Pre);
          loop invariant rightElement == \at(rightElement,Pre);
          loop invariant a_len == \at(a_len,Pre);
          loop invariant a == \at(a,Pre);
          loop invariant i >= \at(leftElement,Pre);
          loop invariant j <= \at(rightElement,Pre);
          loop invariant \at(leftElement,Pre) > \at(rightElement,Pre) ==> i == \at(leftElement,Pre) && j == \at(rightElement,Pre);
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
