
/*@
predicate valid_pairs(int *pairs, integer len) = \valid(pairs + (0..len-1));
*/

/*@
  requires \valid(&pairs[0] + (0..pairs_len-1));
  requires \forall integer i; 0 <= i < pairs_len ==> 0 <= pairs[i] <= 100;
*/

int foo245(int * pairs, int pairs_len, int num, int p) {

    int ret = 0;
    
    /*@
      loop invariant 0 <= index && index <= num;
      loop invariant valid_pairs(pairs, pairs_len);
      loop invariant 0 <= ret && ret <= (num*(num-1))/2;
      loop invariant \forall integer i; 0 <= i < index ==>
                        (\forall integer j; i < j && j < num ==> \true);
      loop invariant \forall integer k; 0 <= k < pairs_len ==> 0 <= pairs[k] <= 100;
      loop assigns index, j, ret;
    */
    for (int index = 0; index < num; index++) {
    
        /*@
          loop invariant index + 1 <= j <= num;
          loop invariant 0 <= index && index < num;
          loop invariant valid_pairs(pairs, pairs_len);
          loop invariant 0 <= ret;
          loop invariant \forall integer i; 0 <= i < index ==>
                    (\forall integer j; i < j && j < num ==> \true);
          loop assigns j, ret;
        */
        for (int j = index + 1; j < num; j++) {
            if (pairs[index] + pairs[j] == p) {
                ret++;
            }
        }
        
    }
    
    return ret;
}
