
/*@
  logic integer sum(int* array, integer begin, integer end) =
    end <= begin ? 0 : sum(array, begin, end - 1) + array[end - 1];
*/

/*@
  logic integer prefix_sum(int* array, integer len) =
    len <= 0 ? 0 : sum(array, 0, len);
*/

/*@
  predicate unchanged_array{L1, L2}(int* array, integer len) =
    \forall integer k; 0 <= k < len ==> \at(array[k], L1) == \at(array[k], L2);
*/

/*@
  assigns \nothing;
  ensures unchanged_array{Pre,Here}(bits, \at(bits_len, Pre));
*/
int foo44(int * bits, int bits_len) {

    int n = bits_len, i = 0;

    /*@
      loop invariant (!(0 < \at(bits_len, Pre) - 1)) ==> ((i == 0) && (n == \at(bits_len, Pre)) && (bits_len == \at(bits_len, Pre)) && (bits == \at(bits, Pre)));
      loop invariant n == \at(bits_len, Pre);
      loop invariant bits_len == \at(bits_len, Pre);
      loop invariant bits == \at(bits, Pre);
      loop invariant unchanged_array{Pre,Here}(bits, bits_len);
      loop assigns i;
    */
    while (i < n - 1) {
        i += bits[i] + 1;
    }

    return i == n - 1;
}
