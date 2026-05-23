
/*@
  logic integer sum(int* array, integer begin, integer end) =
    end <= begin ? 0 : sum(array, begin, end - 1) + array[end - 1];
*/

/*@
  logic integer prefix_sum(int* array, integer len) =
    len <= 0 ? 0 : sum(array, 0, len);
*/

/*@
  logic integer count_non_negative(int* array, integer begin, integer end) =
    begin >= end ? 0 : count_non_negative(array, begin, end - 1) + (array[end - 1] >= 0 ? 1 : 0);
*/

/*@
  predicate unchanged_array(int* array, integer len, int* array_pre) =
    \forall integer k; 0 <= k < len ==> array[k] == \at(array_pre[k], Pre);
*/

/*@
  assigns i;
  ensures \result == ((\exists integer k; 0 <= k < bits_len && 
                       (\forall integer j; 0 <= j < k ==> i == \at(i, Pre) + bits[\at(i, Pre)] + 1) && 
                       i == bits_len - 1));
*/
int foo44(int * bits, int bits_len) {

    int n = bits_len, i = 0;

    /*@
      loop invariant (0 < \at(bits_len,Pre) - 1) ==> (i >= 0 && i <= n - 1);
      loop invariant (!(0 < \at(bits_len,Pre) - 1)) ==> ((i == 0)&&(n == \at(bits_len,Pre))&&(bits_len == \at(bits_len,Pre))&&(bits == \at(bits,Pre)));
      loop invariant n == \at(bits_len,Pre);
      loop invariant bits_len == \at(bits_len,Pre);
      loop invariant bits == \at(bits,Pre);
      loop invariant unchanged_array(bits, bits_len, bits);
      loop assigns i;
    */
    while (i < n - 1) {
        i += bits[i] + 1;
    }

    return i == n - 1;
}
