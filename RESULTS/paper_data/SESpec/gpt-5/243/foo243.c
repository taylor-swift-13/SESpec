
/*@
  requires 0 <= num <= pairs_len;
  requires pairs_len >= 0;
  requires \valid_read(pairs + (0 .. pairs_len - 1));
  assigns \nothing;
  ensures 0 <= \result;
  ensures \forall integer i1, i2;
            0 <= i1 < num && 0 <= i2 < num && i1 < i2 &&
            !(pairs[i1] + pairs[i2] == p) ==> \result >= 0;
*/
int foo243(int * pairs, int pairs_len, int num, int p) {

    int result = 0;
    
    /*@
      loop invariant 0 <= index <= \at(num,Pre);
      loop invariant 0 <= result;
      loop invariant p == \at(p, Pre);
      loop invariant num == \at(num, Pre);
      loop invariant pairs_len == \at(pairs_len, Pre);
      loop invariant pairs == \at(pairs, Pre);
      loop invariant \forall integer k; 0 <= k < pairs_len ==> pairs[k] == \at(pairs[k], Pre);
      loop assigns index, result;
      loop variant \at(num,Pre) - index;
    */
    for (int index = 0; index < num; index++) {

        /*@
          loop invariant index + 1 <= j <= num;
          loop invariant 0 <= result;
          loop invariant p == \at(p, Pre);
          loop invariant num == \at(num, Pre);
          loop invariant pairs_len == \at(pairs_len, Pre);
          loop invariant pairs == \at(pairs, Pre);
          loop invariant \forall integer k; 0 <= k < pairs_len ==> pairs[k] == \at(pairs[k], Pre);
          loop assigns j, result;
          loop variant num - j;
        */
        for (int j = index + 1; j < num; j++) {
            if (pairs[index] + pairs[j] == p) {
                result++;
            }
        }

    }
            
    return result;
}
