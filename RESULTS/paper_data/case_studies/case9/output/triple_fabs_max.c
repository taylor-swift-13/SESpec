
/*@
ensures (-c > -a) && (-b <= -a) && (c < 0) && (b < 0) && (a < 0) ==> (\result == -c);
ensures (-c > a) && (-b <= a) && (c < 0) && (b < 0) && (a >= 0) ==> (\result == -c);
ensures (-c > a) && (b <= a) && (c < 0) && (b >= 0) && (a >= 0) ==> (\result == -c);
ensures (-c > -a) && (b <= -a) && (c < 0) && (b >= 0) && (a < 0) ==> (\result == -c);
ensures (c > -a) && (b <= -a) && (c >= 0) && (b >= 0) && (a < 0) ==> (\result == c);
ensures (c > a) && (b <= a) && (c >= 0) && (b >= 0) && (a >= 0) ==> (\result == c);
ensures (c > a) && (-b <= a) && (c >= 0) && (b < 0) && (a >= 0) ==> (\result == c);
ensures (c > -a) && (-b <= -a) && (c >= 0) && (b < 0) && (a < 0) ==> (\result == c);
ensures (c > -b) && (-b > -a) && (c >= 0) && (b < 0) && (a < 0) ==> (\result == c);
ensures (c > -b) && (-b > a) && (c >= 0) && (b < 0) && (a >= 0) ==> (\result == c);
ensures (c > b) && (b > a) && (c >= 0) && (b >= 0) && (a >= 0) ==> (\result == c);
ensures (c > b) && (b > -a) && (c >= 0) && (b >= 0) && (a < 0) ==> (\result == c);
ensures (-c > b) && (b > -a) && (c < 0) && (b >= 0) && (a < 0) ==> (\result == -c);
ensures (-c > b) && (b > a) && (c < 0) && (b >= 0) && (a >= 0) ==> (\result == -c);
ensures (-c > -b) && (-b > a) && (c < 0) && (b < 0) && (a >= 0) ==> (\result == -c);
ensures (-c > -b) && (-b > -a) && (c < 0) && (b < 0) && (a < 0) ==> (\result == -c);
ensures (-c <= -b) && (-b > -a) && (c < 0) && (b < 0) && (a < 0) ==> (\result == -b);
ensures (-c <= -b) && (-b > a) && (c < 0) && (b < 0) && (a >= 0) ==> (\result == -b);
ensures (-c <= b) && (b > a) && (c < 0) && (b >= 0) && (a >= 0) ==> (\result == b);
ensures (-c <= b) && (b > -a) && (c < 0) && (b >= 0) && (a < 0) ==> (\result == b);
ensures (c <= b) && (b > -a) && (c >= 0) && (b >= 0) && (a < 0) ==> (\result == b);
ensures (c <= b) && (b > a) && (c >= 0) && (b >= 0) && (a >= 0) ==> (\result == b);
ensures (c <= -b) && (-b > a) && (c >= 0) && (b < 0) && (a >= 0) ==> (\result == -b);
ensures (c <= -b) && (-b > -a) && (c >= 0) && (b < 0) && (a < 0) ==> (\result == -b);
ensures (c <= -a) && (-b <= -a) && (c >= 0) && (b < 0) && (a < 0) ==> (\result == -a);
ensures (c <= a) && (-b <= a) && (c >= 0) && (b < 0) && (a >= 0) ==> (\result == a);
ensures (c <= a) && (b <= a) && (c >= 0) && (b >= 0) && (a >= 0) ==> (\result == a);
ensures (c <= -a) && (b <= -a) && (c >= 0) && (b >= 0) && (a < 0) ==> (\result == -a);
ensures (-c <= -a) && (b <= -a) && (c < 0) && (b >= 0) && (a < 0) ==> (\result == -a);
ensures (-c <= a) && (b <= a) && (c < 0) && (b >= 0) && (a >= 0) ==> (\result == a);
ensures (-c <= a) && (-b <= a) && (c < 0) && (b < 0) && (a >= 0) ==> (\result == a);
ensures (-c <= -a) && (-b <= -a) && (c < 0) && (b < 0) && (a < 0) ==> (\result == -a);

assigns \nothing;
*/

int triple_fabs_max(int a, int b, int c)

{
    int fa = a; if (fa < 0) fa = -fa;
    int fb = b; if (fb < 0) fb = -fb;
    int fc = c; if (fc < 0) fc = -fc;
    int m = fa;
    if (fb > m) m = fb;
    if (fc > m) m = fc;
    return m;
}