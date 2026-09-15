
/*@
  logic integer sum(int* array, integer begin, integer end) =
    end <= begin ? 0 : sum(array, begin, end - 1) + array[end - 1];
*/

/*@
  logic integer count_eq{L}(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

/*@
  requires \valid(&bits[0] + (0..bits_len-1));
  requires \forall integer i; 0 <= i < bits_len ==> 0 <= bits[i] <= 100;
  requires bits_len > 0;
  requires bits_len < 100;
  assigns i;
  ensures \result == 1 <==> i == bits_len - 1;
  ensures \result == 0 <==> i != bits_len - 1;
  ensures i >= bits_len - 1;
  ensures i == \at(i, Pre) + sum(bits, 0, bits_len - 1) + count_eq(bits, 0, bits_len - 1, 0);
*/
int foo44(int * bits, int bits_len) {

    int n = bits_len, i = 0;
    
    /*@
      loop invariant 0 <= i <= n;
      loop invariant n == \at(bits_len,Pre);
      loop invariant bits_len == \at(bits_len,Pre);
      loop invariant bits == \at(bits,Pre);
      loop invariant i == \at(i, Pre) + sum(bits, 0, i) + count_eq(bits, 0, i, 0);
      loop assigns i;
      loop variant n - i;
    */
    while (i < n - 1) {
        i += bits[i] + 1;
    }
        
    return i == n - 1;
}
