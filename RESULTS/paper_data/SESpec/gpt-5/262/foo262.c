

/*@
  requires \valid(&a[0] + (0..a_len-1));
  requires \forall integer i; 0 <= i < a_len ==> 0 <= a[i] <= 100;
  assigns \nothing;
  ensures a == \old(a) && a_len == \old(a_len) && x == \old(x);
  ensures \forall integer k; 0 <= k < a_len ==> a[k] == \old(a[k]);
*/
int foo262(int * a, int a_len, int x) {

        int left = 0;
        int right = a_len - 1;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant (left <= right) ==> (0 <= left && right < \at(a_len,Pre));
          loop invariant x == \at(x,Pre);
          loop invariant a_len == \at(a_len,Pre);
          loop invariant a == \at(a,Pre);
          loop invariant \forall integer k; 0 <= k && k < \at(a_len,Pre) ==> a[k] == \at(a[k],Pre);
          loop assigns left, right;
            */
            while (left <= right) {
            int mid = (left + right) / 2;
            if (a[mid] == x) {
                return mid;
            } else if (a[mid] < x) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
            
        return left;
}
