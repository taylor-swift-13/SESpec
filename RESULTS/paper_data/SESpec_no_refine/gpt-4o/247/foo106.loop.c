
/*@
  logic integer count_inversions(int* indices, integer lo, integer hi) =
    lo >= hi ? 0
             : count_inversions(indices, lo, hi - 1) +
               (\exists integer j; lo <= j < hi && indices[lo] > indices[j] ? 1 : 0);
*/

/*@
  requires \valid(indices + (0 .. indices_len - 1));
  requires indices_len >= 0;
  requires num >= 0 && num <= indices_len;
  ensures \result >= 0;
  ensures \result == count_inversions(indices, 0, num);
*/
int foo106(int * indices, int indices_len, int num) {

    int ret = 0;

    /*@
      loop invariant 0 <= index <= num;
      loop invariant ret >= 0;
      loop invariant ret == count_inversions(indices, 0, index);
      loop invariant num == \at(num, Pre);
      loop invariant indices_len == \at(indices_len, Pre);
      loop invariant indices == \at(indices, Pre);
      loop assigns index, ret;
    */
    for (int index = 0; index < num; index++) {
        
        /*@
          loop invariant index + 1 <= c <= num;
          loop invariant ret >= 0;
          loop invariant ret == count_inversions(indices, 0, index) +
                                count_inversions(indices + index, index + 1, c);
          loop invariant num == \at(num, Pre);
          loop invariant indices_len == \at(indices_len, Pre);
          loop invariant indices == \at(indices, Pre);
          loop assigns c, ret;
        */
        for (int c = index + 1; c < num; c++) {
            if (indices[index] > indices[c]) {
                ret++;
            }
        }
    }
    return ret;
}
