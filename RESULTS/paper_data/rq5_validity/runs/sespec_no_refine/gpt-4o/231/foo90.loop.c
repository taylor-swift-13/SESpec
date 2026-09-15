
/*@
  logic integer count_distinct_pairs(int* p, integer lo, integer hi) =
    lo >= hi ? 0
             : count_distinct_pairs(p, lo, hi - 1) +
               (\forall integer j; lo <= j < hi ==> p[hi - 1] != p[j] ? 1 : 0);
*/

/*@
  requires \valid(p + (0 .. p_len - 1));
  requires p_len > 0;
  ensures \result >= 0;
  ensures \result <= (p_len * (p_len - 1)) / 2;
*/
int foo90(int * p, int p_len, int array) {

    int count = 0;
    int total = p_len;
    
    /*@
      loop invariant 0 <= index <= total - 1;
      loop invariant count >= 0;
      loop invariant count == count_distinct_pairs(p, 0, index);
      loop invariant total == \at(p_len, Pre);
      loop invariant array == \at(array, Pre);
      loop invariant p_len == \at(p_len, Pre);
      loop invariant p == \at(p, Pre);
      loop assigns index, c, count;
    */
    for (int index = 0; index < total - 1; index++) {
        
        /*@
          loop invariant index + 1 <= c <= total;
          loop invariant count >= 0;
          loop invariant count == count_distinct_pairs(p, 0, index) +
                                  count_distinct_pairs(p + index + 1, 0, c - (index + 1));
          loop assigns c, count;
        */
        for (int c = index + 1; c < total; c++) {
            if (p[index] != p[c]) {
                count++;
            }
        }
        
    }
    
    return count;
}
