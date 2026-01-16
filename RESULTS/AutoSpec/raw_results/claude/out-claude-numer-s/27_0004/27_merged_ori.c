/*@
  requires x >= 0;
  requires y >= 1;
*/
int hoo27(int x,int y) {
    int q = 0;
    int a = 0;
    int b = x;

    /*@
    loop invariant q * y + a + b == x;
    loop invariant b <= x;
    loop invariant a < y;
    loop invariant 0 <= b;
    loop invariant 0 <= a;
    loop assigns q;
    loop assigns b;
    loop assigns a;
    */
    while(b != 0) {
        if (a + 1 == y) {
            q = q + 1;
            a = 0;
            b = b - 1;
        }
        else {
            a = a + 1;
            b = b - 1;
        }
    }

    /*@ assert q * y + a + b == x; */
}