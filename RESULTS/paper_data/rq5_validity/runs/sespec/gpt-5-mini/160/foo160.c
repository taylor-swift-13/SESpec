
/*@
  logic integer count_eq{L}(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
             : count_eq(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

/*@
  requires \valid(positions + (0..positions_len-1));
  requires \at(positions_len,Pre) > 0 && \at(positions_len,Pre) < 100;
  requires positions_len == \at(positions_len,Pre);
  requires positions == \at(positions,Pre);
  requires array == \at(array,Pre);
  assigns positions[0 .. \at(positions_len,Pre)-1];
  ensures (\exists integer k; 0 <= k < \at(array,Pre) && (\at(positions,Pre)[k] != k + 1) && 
             (\forall integer j; 0 <= j < k ==> \at(positions,Pre)[j] == j + 1) 
             ==> \result == k + 1);
  ensures (\forall integer v; 1 <= v <= \at(array,Pre) ==>
             count_eq(positions, 0, \at(positions_len,Pre), v) == count_eq(\at(positions,Pre), 0, \at(positions_len,Pre), v));
*/
int foo160(int * positions, int positions_len, int array) {

    int ret = 0;
        
    /*@
      loop invariant 0 <= ret;
      loop invariant (0 < \at(array,Pre)) ==> (0 <= ret); 
      loop invariant (0 < \at(array,Pre)) ==> (ret >= 0);
      loop invariant (!(0 < \at(array,Pre))) ==> ((ret == 0)&&(array == \at(array,Pre))&&(positions_len == \at(positions_len,Pre))&&(positions == \at(positions,Pre)));
      loop invariant array == \at(array,Pre);
      loop invariant positions_len == \at(positions_len,Pre);
      loop invariant positions == \at(positions,Pre);
      loop invariant \valid(positions + (0 .. \at(positions_len,Pre)-1));
      loop invariant (\forall integer v; 1 <= v <= \at(array,Pre) ==>
                     count_eq(positions, 0, \at(array,Pre), v) == count_eq(\at(positions,Pre), 0, \at(array,Pre), v));
      loop assigns ret, positions[0..\at(positions_len,Pre)-1];
    */
    while (ret < array) {
        if (positions[ret] <= 0 || positions[ret] > array
                || positions[ret] == ret + 1) {
            ret++;
        } else {
            int index = positions[ret];
            positions[ret] = positions[index - 1];
            positions[index - 1] = index;
        }
    }
            
    /*@
      loop invariant 0 <= ret;
      loop invariant (ret < array) ==> (\forall integer k; 0 <= k < ret ==> positions[k] == k + 1);
      loop invariant array == \at(array,Pre) && positions == \at(positions,Pre);
      loop assigns ret;
    */
    for (ret = 0; ret < array; ret++) {
        if (positions[ret] != ret + 1) {
            return ret + 1;
        }
    }
    return array + 1;
}
