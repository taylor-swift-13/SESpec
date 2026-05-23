
/*@
*/

/*@
  requires \valid(&x[0] + (0..x_len-1));
  requires \forall integer i; 0 <= i < x_len ==> 0 <= x[i] <= 100;
  requires x_len > 0;
  requires x_len < 100;
  requires \valid(&y[0] + (0..y_len-1));
  requires \forall integer i; 0 <= i < y_len ==> 0 <= y[i] <= 100;
  requires y_len > 0;
  requires y_len < 100;
  assigns \nothing;
  ensures (\result == 1) <==> (x_len == y_len && (\forall integer i; 0 <= i < x_len ==> x[i] == y[x_len - 1 - i]));
  ensures (\result == 0) <==> (x_len != y_len || (\exists integer i; 0 <= i < x_len && x[i] != y[x_len - 1 - i]));
  ensures \result == ((x_len == y_len && (\forall integer i; 0 <= i < x_len ==> x[i] == y[x_len - 1 - i])) ? 1 : 0);
*/
int foo111(int * x, int x_len, int * y, int y_len) {

        if (x_len != y_len) return 0;
        int index = 0;

        /*@ 
          loop invariant 0 <= index <= x_len;
          loop invariant \forall integer k; 0 <= k < index ==> x[k] == y[x_len - 1 - k];
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
