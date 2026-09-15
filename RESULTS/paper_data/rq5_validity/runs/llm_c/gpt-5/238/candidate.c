/*@ 
  logic integer odd01(int x, int y) = (((x ^ y) % 2) == 1 ? 1 : 0);

  logic integer count_pairs_from_i_prefix{L}(int *a, integer length, integer i, integer j) =
    j <= i + 1 ? 0 :
      count_pairs_from_i_prefix(a, length, i, j - 1) + odd01(a[i], a[j - 1]);

  logic integer count_prefix{L}(int *a, integer length, integer i) =
    i <= 0 ? 0 :
      count_prefix(a, length, i - 1) + count_pairs_from_i_prefix(a, length, i - 1, length);
*/

/*@ 
  requires a_len >= 0;
  requires \valid_read(a + (0 .. a_len-1));
  assigns \nothing;

  ensures \result == count_prefix(a, a_len, a_len);
  ensures 0 <= \result <= (a_len * (a_len - 1)) / 2;
  ensures a_len <= 1 ==> \result == 0;
*/
int findOddPair(int * a, int a_len, int n);

int findOddPair(int * a, int a_len, int n) {

        int count = 0;
        int length = a_len;
        /*@
          loop invariant 0 <= i <= length;
          loop invariant \valid_read(a + (0 .. length-1));
          loop invariant count == count_prefix(a, length, i);
          loop assigns i, count;
          loop variant length - i;
        */
        for (int i = 0; i < length; i++) {
            /*@
              loop invariant i + 1 <= j <= length;
              loop invariant \valid_read(a + (0 .. length-1));
              loop invariant count == count_prefix(a, length, i) + count_pairs_from_i_prefix(a, length, i, j);
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
