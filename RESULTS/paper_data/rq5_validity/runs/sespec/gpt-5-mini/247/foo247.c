
/*@
  logic integer count_inv(int* a, integer n, integer idx) =
    idx <= 0 ? 0
    : count_inv(a, n, idx - 1)
      + (\sum integer j; (idx - 1) + 1 <= j < n; (a[idx - 1] > a[j] ? 1 : 0));
*/

/*@
  requires \valid(&indices[0] + (0..indices_len-1));
  requires \forall integer i; 0 <= i < indices_len ==> 0 <= indices[i] <= 100;
  requires indices_len > 0;
  requires indices_len < 100;
  requires 0 <= num <= indices_len;
  assigns \nothing;
  ensures \result == \old(count_inv(indices, \at(num,Pre), num));
*/
int foo247(int * indices, int indices_len, int num) {

    int ret = 0;

    /*@
      loop invariant num == \at(num,Pre);
      loop invariant indices_len == \at(indices_len,Pre);
      loop invariant \forall integer k; 0 <= k < indices_len ==> indices[k] == \at(indices[k],Pre);
      loop invariant 0 <= ret;
      loop invariant 0 <= index <= num;
      loop invariant ret == count_inv(indices, \at(num,Pre), index);
      loop assigns index, c, ret;
    */
    for (int index = 0; index < num; index++) {

        /*@
          loop invariant num == \at(num,Pre);
          loop invariant indices_len == \at(indices_len,Pre);
          loop invariant \forall integer k; 0 <= k < indices_len ==> indices[k] == \at(indices[k],Pre);
          loop invariant 0 <= ret;
          loop invariant index + 1 <= c <= num;
          loop invariant ret == count_inv(indices, \at(num,Pre), index);
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
