
/*@
  logic integer idx_sum(integer n) = n;
*/

int foo129(int * a, int a_len, int x) {

        int left = 0;
        int right = a_len - 1;
        
            
        /*@
          loop invariant (0 <= a_len - 1) ==> (((right == a_len - 1)&&(left == 0)&&(x == \at(x,Pre))&&(a_len == \at(a_len,Pre))&&(a == \at(a,Pre))) || (left >= 0));
          loop invariant (0 <= a_len - 1) ==> (((right == a_len - 1)&&(left == 0)&&(x == \at(x,Pre))&&(a_len == \at(a_len,Pre))&&(a == \at(a,Pre))) || (right < a_len));
          loop invariant (!(0 <= a_len - 1)) ==> ((right == a_len - 1)&&(left == 0)&&(x == \at(x,Pre))&&(a_len == \at(a_len,Pre))&&(a == \at(a,Pre)));
          loop invariant x == \at(x,Pre);
          loop invariant a_len == \at(a_len,Pre);
          loop invariant a == \at(a,Pre);
          loop invariant 0 <= left <= a_len;
          loop invariant -1 <= right < a_len;
          loop invariant left <= right + 1;
          loop invariant \valid_read(a + (0 .. a_len - 1));
          loop assigns mid, left, right;
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
