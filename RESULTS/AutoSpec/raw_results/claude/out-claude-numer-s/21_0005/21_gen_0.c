/*@
  requires X > 0;
  requires Y > 0;
  requires X >= Y;
*/
int hoo21(int X,int Y) {
    
    int v, x, y;

    v = 2 * Y - X;
    y = 0;
    x = 0;


    
    /*@
    loop invariant 0 <= x <= X + 1;
    loop invariant v == 2*Y*(y + 1) - 2*X*x + 2*y - X;
    loop invariant y <= x;
    loop assigns x, y, v;
    */
    while (x <= X) {
        if (v < 0) {
            v = v + 2 * Y;
        } else {
            v = v + 2 * (Y - X);
            y++;
        }
        x++;

    }

    
    /*@ assert 2*Y*x - 2*x*y - X + 2*Y - v + 2*y == 0; */
}