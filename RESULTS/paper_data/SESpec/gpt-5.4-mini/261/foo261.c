

/*@
  requires \valid(&a[0] + (0..a_len-1));
  requires \forall integer i; 0 <= i < a_len ==> 0 <= a[i] <= 100;
  assigns \nothing;
  ensures a_len <= 0 ==> \result == 0;
  ensures a_len > 0 ==> 0 <= \result <= a_len;
  ensures a == \at(a,Pre);
  ensures x == \at(x,Pre);
  ensures a_len == \at(a_len,Pre);
  ensures \result == (a_len <= 0 ? 0 : \result);
*/
int foo261(int * a, int a_len, int x) {

        int i = 0;
        int j = a_len - 1;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= i;
          loop invariant j < \at(a_len,Pre);
          loop invariant a_len < 0 || i <= j + 1;

          loop invariant (0 <= \at(a_len,Pre) - 1) ==> (((j == \at(a_len,Pre) - 1)&&(i == 0)&&(x == \at(x,Pre))&&(a_len == \at(a_len,Pre))&&(a == \at(a,Pre))) || (0 <= i <= \at(a_len,Pre)));
          loop invariant (0 <= \at(a_len,Pre) - 1) ==> (((j == \at(a_len,Pre) - 1)&&(i == 0)&&(x == \at(x,Pre))&&(a_len == \at(a_len,Pre))&&(a == \at(a,Pre))) || (-1 <= j < \at(a_len,Pre)));
          loop invariant (!(0 <= \at(a_len,Pre) - 1)) ==> ((j == \at(a_len,Pre) - 1)&&(i == 0)&&(x == \at(x,Pre))&&(a_len == \at(a_len,Pre))&&(a == \at(a,Pre)));
          loop invariant x == \at(x,Pre);
          loop invariant a_len == \at(a_len,Pre);
          loop invariant a == \at(a,Pre);
          loop invariant \forall integer k; 0 <= k < \at(a_len,Pre) ==> a[k] == \at(a[k],Pre);
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
