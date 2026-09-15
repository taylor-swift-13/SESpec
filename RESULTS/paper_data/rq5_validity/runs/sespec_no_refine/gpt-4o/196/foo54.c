
/*@
  logic integer max(int* array, integer begin, integer end) =
    end <= begin ? Integer.MIN_VALUE : 
    (array[end - 1] > max(array, begin, end - 1) ? array[end - 1] : max(array, begin, end - 1));
*/

/*@
  requires \valid(a + (0..a_len-1));
  requires a_len > 0;
  ensures \result == max(a, 0, a_len);
  assigns \nothing;
*/
int foo54(int * a, int a_len) {

    if (a_len == 0) return -1;
    int res = Integer.MIN_VALUE;

    /*@
      loop invariant 0 <= i <= a_len;
      loop invariant res == max(a, 0, i);
      loop invariant \forall integer k; 0 <= k < a_len ==> a[k] == \at(a[k], Pre);
      loop assigns i, res;
      loop variant a_len - i;
    */
    for (int i = 0; i < a_len; i++) {
        res = ((a[i] > res) ? a[i] : res);
    }

    return res;
}
