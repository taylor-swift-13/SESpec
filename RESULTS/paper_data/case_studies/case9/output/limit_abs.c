
/*@
ensures (x >= -lim) && (x <= lim) ==> (\result == x);
ensures (x < -lim) && (x <= lim) ==> (\result == -lim);
ensures (x > lim) ==> (\result == lim);

assigns \nothing;
*/

int limit_abs(int x, int lim)

{
    if (x >  lim) return  lim;
    if (x < -lim) return -lim;
    return x;
}