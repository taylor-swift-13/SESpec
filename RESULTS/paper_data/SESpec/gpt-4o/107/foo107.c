
/*@
  logic integer count_nonzero(int* x, integer lo, integer hi) =
    lo >= hi ? 0
             : count_nonzero(x, lo, hi - 1) + (x[hi - 1] != 0 ? 1 : 0);
*/

/*@
  requires \valid(x + (0..x_len-1));
  requires x_len >= 0;
  ensures \result == -1 || (0 <= \result < x_len && x[\result] == 0);
  ensures \forall integer i; 0 <= i < \result ==> x[i] != 0;
  ensures \result == -1 ==> \forall integer i; 0 <= i < x_len ==> x[i] != 0;
  assigns \nothing;
*/
int foo107(int * x, int x_len) {
    assert(x_len >= 0);
    if (x_len == 0) {
        return -1;
    } else {
        int index = 0;

        /*@
          loop invariant 0 <= index <= x_len;
          loop invariant count_nonzero(x, 0, index) == index;
          loop invariant \forall integer i; 0 <= i < index ==> x[i] != 0;
          loop invariant (x_len - index > 0 && x[index] != 0) ==> (\forall integer i; 0 <= i < index ==> x[i] != 0);
          loop invariant (!(x_len - index > 0 && x[index] != 0)) ==> (index == x_len || x[index] == 0);
          loop invariant \forall integer i; 0 <= i < x_len ==> x[i] == \at(x[i], Pre);
          loop assigns index;
        */
        while (x_len - index > 0 && x[index] != 0) {
            index = index + 1;
        }

        if (x_len - index == 0) {
            index = -1;
        }
        return index;
    }
}
