
/*@
predicate valid_pairs(int *pairs, integer len) = \valid(pairs + (0..len-1));
*/

/*@
  logic integer count_with_last(int *pairs, integer num, integer p, integer i) =
    i >= num-1 ? 0
    : ( (pairs[i] + pairs[num-1] == p) ? 1 : 0 )
      + count_with_last(pairs, num, p, i+1);
*/

/*@
  logic integer count_pairs(int *pairs, integer num, integer p) =
    num <= 1 ? 0
    : count_pairs(pairs, num-1, p) + count_with_last(pairs, num, p, 0);
*/

/*@
  requires valid_pairs(pairs, pairs_len);
  requires \forall integer i; 0 <= i < pairs_len ==> 0 <= pairs[i] <= 100;
  requires pairs_len >= num;
  requires num >= 0;
  assigns \nothing;
  ensures 0 <= \result && \result <= (num*(num-1))/2;
  ensures \result == count_pairs(pairs, num, p);
  ensures num <= 1 ==> \result == 0;
  ensures \result == 0 <==> (\forall integer i,j; 0 <= i < j && j < num ==> pairs[i] + pairs[j] != p);
*/
int foo245(int * pairs, int pairs_len, int num, int p) {

    int ret = 0;
    
    /*@ 
      loop invariant 0 <= index && index <= num;
      loop invariant valid_pairs(pairs, pairs_len);
      loop invariant index == 0 ==> ret == 0;
      loop invariant \forall integer k; 0 <= k < pairs_len ==> 0 <= pairs[k] <= 100;
      loop assigns ret;
    */
    for (int index = 0; index < num; index++) {
    
        /*@
          loop invariant index + 1 <= j && j <= num;
          loop invariant 0 <= index && index < num;
          loop invariant valid_pairs(pairs, pairs_len);
          loop invariant 0 <= ret;
          loop invariant ret >= count_pairs(pairs, index, p);
          loop invariant \forall integer k; 0 <= k < pairs_len ==> 0 <= pairs[k] <= 100;
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
