
/*@
  requires \valid(indices + (0 .. indices_len - 1));
  requires num >= 0 && indices_len >= num;
  assigns \nothing;
  ensures \result >= 0;
  
*/
int foo247(int * indices, int indices_len, int num) {

    int ret = 0;

    /*@
      loop invariant 0 <= index <= num;
      loop invariant ret >= 0;
      loop invariant num == \at(num, Pre);
      loop invariant indices_len == \at(indices_len, Pre);
      loop invariant indices == \at(indices, Pre);
      loop assigns index, ret;
    */
    for (int index = 0; index < num; index++) {
        
        /*@
          loop invariant index + 1 <= c <= num;
          loop invariant ret >= 0;
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
