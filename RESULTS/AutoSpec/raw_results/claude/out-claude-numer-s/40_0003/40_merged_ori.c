/*@
  requires a > 2;
*/
int hoo40(int a) {
    //algorithm searching for a divisor for factorization, by Knuth
    int r, k, q, d, n, t, s;
    
    
    n = s*s;
    d = a;
    r = n % d;
    t = 0;
    k = n % (d - 2);
    q = 4 * (n / (d - 2) - n / d);

    /*@
    loop invariant s*s == n;
    loop invariant s >= d || r != 0;
    loop invariant s - d;
    loop invariant r == n % d || (d > 0 && r >= 0);
    loop invariant q == 4 * (n / (d - 2) - n / d);
    loop invariant k == n % (d - 2) || (d > 2 && k >= 0);
    loop invariant d > 0 && (d % 2 == 0 || d % 2 == 1);
    loop invariant d == \old(d) + 2 * (s - d) / 2;
    loop invariant 0 <= t;
    loop assigns t;
    loop assigns r;
    loop assigns q;
    loop assigns k;
    loop assigns d;
    */
    while (((s >= d) && (r != 0))) {
        if (2 * r  + q < k) {
            t = r;
            r = 2 * r - k + q + d + 2;
            k = t;
            q = q + 4;
            d = d + 2;
        } else if ((2 * r  + q >= k) && (2 * r + q < d + k + 2)) {
            t = r;
            r = 2 * r - k + q;
            k = t;
            d = d + 2;
        } else if ((2 * r  + q >= k) && (2 * r + q >= d + k + 2) && (2 * r + q < 2 * d + k + 4)) {
            t = r;
            r = 2 * r - k + q - d - 2;
            k = t;
            q = q - 4;
            d = d + 2;
        } else {
            t = r;
            r = 2 * r - k + q - 2 * d - 4;
            k = t;
            q = q - 8;
            d = d + 2;
        }
    }

    /*@ assert d * d * q - 2 * d * q - 4 * d * r + 4 * d * t + 4 * a * k - 4 * a * t - 8 * n + 8 * r == 0; */
}