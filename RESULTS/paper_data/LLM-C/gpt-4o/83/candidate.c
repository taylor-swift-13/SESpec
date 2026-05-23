/*@
    requires k > 0;
    assigns \nothing;
    ensures \true;
*/
int main11(int z, int k, int a) {

    int x = a;
    int y = 1;
    int c = 1;

    /*@
        loop invariant 1 <= c <= k;
        loop invariant x == a * (z^(c-1)) + a * (z^(c-2)) + ... + a * z + a;
        loop invariant y == z^(c-1);
        loop assigns c, x, y;
        loop variant k - c;
    */
    while (c < k) {
        c = c + 1;
        x = x * z + a;
        y = y * z;
    }
}
