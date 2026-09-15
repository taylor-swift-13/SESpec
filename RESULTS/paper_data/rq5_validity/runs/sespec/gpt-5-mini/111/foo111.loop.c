
/*@
  logic integer rev_count(int* x, int* y, integer lo, integer hi, integer nlen) =
    lo >= hi ? 0
             : rev_count(x,y,lo,hi-1,nlen) +
               ( x[hi-1] == y[nlen - 1 - (hi-1)] ? 1 : 0 );
*/

/*@
  requires \valid(x + (0..x_len-1));
  requires \valid(y + (0..y_len-1));
  requires \at(x_len,Pre) == \at(y_len,Pre) && \at(x_len,Pre) > 0 && \at(x_len,Pre) < 100 && \at(y_len,Pre) > 0 && \at(y_len,Pre) < 100;
*/
int foo111(int * x, int x_len, int * y, int y_len) {

        if (x_len != y_len) return 0;
        int index = 0;

        /*@
          loop invariant (0 < \at(x_len,Pre)) ==> (rev_count(x,y,0,index,\at(x_len,Pre)) == index);
          loop invariant (0 < \at(x_len,Pre)) ==> (0 <= index && index <= x_len);
          loop invariant (!(0 < \at(x_len,Pre))) ==> ((index == 0)&&(y_len == \at(y_len,Pre))&&(y == \at(y,Pre))&&(x_len == \at(x_len,Pre))&&(x == \at(x,Pre)));
          loop invariant y_len == \at(y_len,Pre);
          loop invariant y == \at(y,Pre);
          loop invariant x_len == \at(x_len,Pre);
          loop invariant x == \at(x,Pre);
          loop invariant \forall integer k; 0 <= k < x_len ==> x[k] == \at(x[k],Pre);
          loop invariant \forall integer k; 0 <= k < y_len ==> y[k] == \at(y[k],Pre);
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
