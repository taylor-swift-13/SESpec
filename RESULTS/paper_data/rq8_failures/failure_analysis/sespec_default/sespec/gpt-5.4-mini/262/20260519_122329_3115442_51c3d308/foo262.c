
/*@ logic integer abs_int(integer x) = x < 0 ? -x : x; */

/*@
  requires \valid(&a[0] + (0..a_len-1));
  requires \forall integer i; 0 <= i < a_len ==> 0 <= a[i] <= 100;
  requires a_len > 0;
  requires a_len < 100;
  requires \forall integer i; 0 <= i < a_len - 1 ==> a[i] <= a[i+1];
  assigns \nothing;
  ensures (\exists integer i; 0 <= i < a_len && a[i] == x ==> a[\result] == x);
*/
int foo262(int * a, int a_len, int x) {

        int left = 0;
        int right = a_len - 1;
        
        /*@
          loop invariant 0 <= left;
          loop invariant x == \at(x,Pre);
          loop invariant a_len == \at(a_len,Pre);
          loop invariant a == \at(a,Pre);
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
