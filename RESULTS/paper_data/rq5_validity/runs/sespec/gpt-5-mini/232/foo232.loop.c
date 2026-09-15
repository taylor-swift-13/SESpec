
/*@
  requires \valid(&pairs[0] + (0..pairs_len-1));
  requires \forall integer i; 0 <= i < pairs_len ==> 0 <= pairs[i] <= 100;
*/
int foo232(int * pairs, int pairs_len, int array) {

    int count = 0;
    int total = pairs_len;

    /*@
      loop invariant total == \at(pairs_len,Pre);
      loop invariant 0 <= count;
      loop invariant array == \at(array,Pre);
      loop invariant pairs_len == \at(pairs_len,Pre);
      loop invariant \forall integer i; 0 <= i < pairs_len ==> 0 <= pairs[i] <= 100;
      loop invariant \forall integer i; 0 <= i < pairs_len ==> pairs[i] == \at(pairs[i],Pre);
      loop assigns \nothing;
    */
    for (int index = 0; index < total - 1; index++) {

        /*@
          loop invariant 0 <= index && index <= total - 1;
          loop invariant 0 <= count;
          loop invariant \forall integer k; 0 <= k < index ==>
                        (\forall integer j; k+1 <= j && j < total ==> pairs[k] != pairs[j] ==> \true);
          loop assigns index, c, count;
        */
        for (int c = index + 1; c < total; c++) {
            if (pairs[index] != pairs[c]) {
                count++;
            }
        }

    }

    return count;
}
