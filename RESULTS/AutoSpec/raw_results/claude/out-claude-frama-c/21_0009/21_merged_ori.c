
/*@
requires a >= 0 && b >= 0;
ensures \result > 0;
ensures \forall integer d; d > 0 && (d | a) && (d | b) ==> d <= \result; // \result is greatest common divisor;
ensures (\result | a) && (\result | b); // \result divides both a and b;
assigns \nothing;
*/
int gcd(int a, int b) 
{
    if (a == 0)
       return b;

    if (b == 0)
       return a;

    if (a == b)
        return a;

    if (a > b)
        return gcd(a-b, b);
    return gcd(a, b-a);
}

int doo2()
{
    int a = 98, b = 56;
    int c = gcd(a, b);
    // @ assert c == 14;
    return 0;
}