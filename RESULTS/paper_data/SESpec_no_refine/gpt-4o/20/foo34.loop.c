
/*@
  logic integer reverse_index(int len, integer idx) = len - 1 - idx;
*/

/*@
  requires \at(x_len,Pre) == \at(y_len,Pre) && \at(x_len,Pre) > 0 && \at(x_len,Pre) < 100 && \at(y_len,Pre) > 0 && \at(y_len,Pre) < 100;
  ensures \result == 1 <==> \forall integer i; 0 <= i < x_len ==> x[i] == y[reverse_index(x_len, i)];
  ensures \result == 0 <==> \exists integer i; 0 <= i < x_len && x[i] != y[reverse_index(x_len, i)];
*/
int foo34(int * x, int x_len, int * y, int y_len) {

    if (x_len != y_len) return 0;
    int index = 0;

    /*@
      loop invariant 0 <= index <= x_len;
      loop invariant \forall integer i; 0 <= i < index ==> x[i] == y[reverse_index(x_len, i)];
      loop invariant y_len == \at(y_len,Pre);
      loop invariant y == \at(y,Pre);
      loop invariant x_len == \at(x_len,Pre);
      loop invariant x == \at(x,Pre);
      loop invariant \forall integer i; 0 <= i < y_len ==> y[i] == \at(y[i],Pre);
      loop invariant \forall integer i; 0 <= i < x_len ==> x[i] == \at(x[i],Pre);
      loop assigns index;
    */
    while (index < x_len) {
        if (x[index] != y[x_len - 1 - index]) {
            return 0;
        } else {
            index = index + 1;
        }
    }

    return 1;
}
