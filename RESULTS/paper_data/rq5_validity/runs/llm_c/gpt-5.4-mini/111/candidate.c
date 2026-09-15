/*@
    requires x_len >= 0;
    requires y_len >= 0;
    requires x_len == y_len;
    requires \valid_read(x + (0 .. x_len - 1));
    requires \valid_read(y + (0 .. y_len - 1));
    assigns \nothing;
    ensures \result == 1 ==> \forall integer i; 0 <= i < x_len ==> x[i] == y[x_len - 1 - i];
    ensures \result == 0 ==> \exists integer i; 0 <= i < x_len && x[i] != y[x_len - 1 - i];
*/
int Inverse(int * x, int x_len, int * y, int y_len);

int Inverse(int * x, int x_len, int * y, int y_len) {

        if (x_len != y_len) return 0;
        int index = 0;

        /*@
            loop invariant 0 <= index <= x_len;
            loop invariant \forall integer i; 0 <= i < index ==> x[i] == y[x_len - 1 - i];
            loop assigns index;
            loop variant x_len - index;
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
