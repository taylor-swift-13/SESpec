
/*@ 
  logic integer is_odd_xor(int x, int y) = ((x ^ y) % 2 == 1 ? 1 : 0);
*/

/*@ 
  logic integer cnt_suffix_from(int* a, integer i, integer j, integer n) =
    j >= n ? 0
           : cnt_suffix_from(a, i, j + 1, n) + (is_odd_xor(a[i], a[j]) ? 1 : 0);
*/

/*@
  logic integer cnt_odd_xor_pairs_up_to_i(int* a, integer n, integer i) =
    i <= 0 ? 0
           : cnt_odd_xor_pairs_up_to_i(a, n, i - 1)
             + cnt_suffix_from(a, i - 1, i, n);
*/

/*@
  requires a_len >= 0;
  requires \valid(a + (0 .. a_len-1));
  requires \forall integer k; 0 <= k < a_len ==> 0 <= a[k] <= 100;

  assigns \nothing;
  ensures \result >= 0;
  ensures \forall integer i; 0 <= i < a_len ==> \at(a[i],Pre) == a[i];
  ensures a_len == \at(a_len,Pre) && a == \at(a,Pre) && n == \at(n,Pre);
*/
int foo238(int * a, int a_len, int n) {

        int count = 0;
        int length = a_len;

        /*@
          loop invariant 0 <= i <= length;
          loop invariant length == \at(a_len,Pre);
          loop invariant n == \at(n,Pre);
          loop invariant a_len == \at(a_len,Pre);
          loop invariant a == \at(a,Pre);
          loop invariant \forall integer k; 0 <= k < length ==> a[k] == \at(a[k],Pre);
          loop invariant \forall integer k; 0 <= k < length ==> 0 <= a[k] <= 100;
          loop invariant 0 <= count;
          loop assigns i, count;
          loop variant length - i;
        */
        for (int i = 0; i < length; i++) {

            /*@
              loop invariant i + 1 <= j <= length;
              loop invariant 0 <= i < length;
              loop invariant 0 <= count;
              loop assigns j, count;
              loop variant length - j;
            */
            for (int j = i + 1; j < length; j++) {
                if ((a[i] ^ a[j]) % 2 == 1) {
                    count++;
                }
            }
        }

        return count;
}
