
/*@
  requires \valid(&pairs[0] + (0..pairs_len-1));
  requires \forall integer i; 0 <= i < pairs_len ==> 0 <= pairs[i] <= 100;
*/
int foo243(int * pairs, int pairs_len, int num, int p) {

    int result = 0;

    /*@
      loop invariant 0 <= index;
      loop invariant 0 <= result;
      loop invariant p == \at(p,Pre);
      loop invariant num == \at(num,Pre);
      loop invariant pairs_len == \at(pairs_len,Pre);
      loop invariant pairs == \at(pairs,Pre);
      loop invariant \forall integer k; 0 <= k < pairs_len ==> 0 <= pairs[k] <= 100;
      loop assigns index, result;
    */
    for (int index = 0; index < num; index++) {

        /*@
          loop invariant index + 1 <= j && j <= num;
          loop invariant 0 <= result;
          loop invariant p == \at(p,Pre);
          loop invariant num == \at(num,Pre);
          loop invariant pairs_len == \at(pairs_len,Pre);
          loop invariant pairs == \at(pairs,Pre);
          loop invariant \forall integer k; 0 <= k < pairs_len ==> 0 <= pairs[k] <= 100;
          loop assigns j, result;
        */
        for (int j = index + 1; j < num; j++) {
            if (pairs[index] + pairs[j] == p) {
                result++;
            }
        }

    }

    return result;
}
