
/*@
  // No additional predicate or logic function is required for this program.
*/

/*@
  requires \valid(&pairs[0] + (0..pairs_len-1));
  requires \forall integer i; 0 <= i < pairs_len ==> 0 <= pairs[i] <= 100;
  requires pairs_len > 0;
  requires pairs_len < 100;
*/

int foo104(int * pairs, int pairs_len, int num, int p) {

    int ret = 0;

    /*@
      loop invariant 0 <= index <= num;
      loop invariant 0 <= ret <= index * (index - 1) / 2;
      loop invariant \forall integer i, j; 0 <= i < index && i < j < num ==> 
          (pairs[i] + pairs[j] == p ==> ret >= 1);
      loop invariant p == p; // Parameters are constant
      loop invariant num == num; // Parameters are constant
      loop invariant pairs_len == pairs_len; // Parameters are constant
      loop invariant \valid(&pairs[0] + (0..pairs_len-1));
      loop invariant \forall integer i; 0 <= i < pairs_len ==> 0 <= pairs[i] <= 100;
      loop assigns ret;
    */
    for (int index = 0; index < num; index++) {

        /*@
          loop invariant index + 1 <= j <= num;
          loop invariant 0 <= ret <= index * (index - 1) / 2 + (j - (index + 1));
          loop invariant \forall integer k, l; 0 <= k <= index && index + 1 <= l < j ==> 
              (pairs[k] + pairs[l] == p ==> ret >= 1);
          loop invariant p == p; // Parameters are constant
          loop invariant num == num; // Parameters are constant
          loop invariant pairs_len == pairs_len; // Parameters are constant
          loop invariant \valid(&pairs[0] + (0..pairs_len-1));
          loop invariant \forall integer i; 0 <= i < pairs_len ==> 0 <= pairs[i] <= 100;
          loop assigns ret;
        */
        for (int j = index + 1; j < num; j++) {
            if (pairs[index] + pairs[j] == p) {
                ret++;
            }
        }

    }

    return ret;
}
