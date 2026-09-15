/*@
    requires \true;
    ensures \result <= 91;
    ensures \result == 91 <==> n <= 101;
    ensures \result == n - 10 <==> n > 101;
    assigns \nothing;
*/
int f(int n);

int f(int n) {

    if (n > 100) return n - 10;
    else return f(f(n + 11));
}
