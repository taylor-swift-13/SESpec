
int limit_abs(int x, int lim)
{
    if (x >  lim) return  lim;
    if (x < -lim) return -lim;
    return x;
}