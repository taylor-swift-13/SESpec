
/*@
requires a >= 0 && b >= 0;
ensures \result != 0 ==> (\exists int k; k > 0 && a % k == 0 && b % k == 0 && \forall int m; m > 0 && a % m == 0 && b % m == 0 ==> m <= k);
ensures \result != 0 && a != 0 && b != 0 ==> a % \result == 0 && b % \result == 0;
ensures \result == 0 <==> (a == 0 && b == 0);
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