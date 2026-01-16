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
    loop invariant y == \numofinteger(i; 0 <= i < x && v_at_i(i) >= 0);
    loop invariant x <= X + 1;
    loop invariant v == v_at_x(x);
    loop invariant 0 <= x;
    loop assigns y;
    loop assigns x;
    loop assigns v;
    (Note: since ACSL cannot express sequences directly, the loop invariant captures the relationship between x, y, and v according to loop logic.);
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