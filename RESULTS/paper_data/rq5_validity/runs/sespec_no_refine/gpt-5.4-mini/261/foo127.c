
/*@
  requires \at(a_len,Pre) > 0 && \at(a_len,Pre) < 100;
  requires \valid_read(a + (0 .. a_len - 1));
  assigns \nothing;
  ensures (\result >= 0 && \result < a_len) ==> a[\result] == x;
  ensures (\result >= 0 && \result < a_len) ==> (\forall integer k; 0 <= k < \result ==> a[k] < x);
  ensures (\result >= 0 && \result < a_len) ==> (\forall integer k; \result < k < a_len ==> a[k] > x);
  ensures (\result == a_len) ==> (\forall integer k; 0 <= k < a_len ==> a[k] < x);
  ensures \result >= 0 && \result <= a_len;
*/
int foo127(int * a, int a_len, int x) {

        int i = 0;
        int j = a_len - 1;
        
            /*@
          loop invariant (0 <= \at(a_len,Pre) - 1) ==> (((j == \at(a_len,Pre) - 1)&&(i == 0)&&(x == \at(x,Pre))&&(a_len == \at(a_len,Pre))&&(a == \at(a,Pre))) || (0 <= i <= a_len));
          loop invariant (0 <= \at(a_len,Pre) - 1) ==> (((j == \at(a_len,Pre) - 1)&&(i == 0)&&(x == \at(x,Pre))&&(a_len == \at(a_len,Pre))&&(a == \at(a,Pre))) || (-1 <= j < a_len));
          loop invariant (!(0 <= \at(a_len,Pre) - 1)) ==> ((j == \at(a_len,Pre) - 1)&&(i == 0)&&(x == \at(x,Pre))&&(a_len == \at(a_len,Pre))&&(a == \at(a,Pre)));
          loop invariant x == \at(x,Pre);
          loop invariant a_len == \at(a_len,Pre);
          loop invariant a == \at(a,Pre);
          loop invariant \valid_read(a + (0 .. a_len - 1));
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
