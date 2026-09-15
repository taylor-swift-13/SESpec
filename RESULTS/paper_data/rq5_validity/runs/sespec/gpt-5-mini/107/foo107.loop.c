
/*@ 
  predicate no_aux_required = \true;
*/

/*@
  requires x_len >= 0;
  requires x_len == 0 || \valid_read(x + (0 .. x_len - 1));
*/
int foo107(int * x, int x_len) {

    assert(x_len >= 0);
    if (x_len == 0) {
        return -1;
    } else {
        int index = 0;

        /*@
          loop invariant 0 <= index <= x_len;
          loop invariant x_len == \at(x_len, Pre);
          loop invariant \valid_read(x + (0 .. (x_len - 1)));
          loop invariant \forall integer k; 0 <= k < index ==> x[k] != 0;
          loop invariant \forall integer k; 0 <= k < x_len ==> x[k] == \at(x[k], Pre);
          loop invariant (x_len - index > 0 && x[index] != 0) ==> (0 <= index && index <= x_len - 1 && x[index] != 0);
          loop invariant (!(x_len - index > 0 && x[index] != 0)) ==> (index == x_len || x[index] == 0);
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
