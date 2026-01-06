
/*@
    requires a <= 1000000 && b >= 0 && b <= 1000000;
*/
void foo191(int a, int b) {
    int res;
    int cnt;

    res = a;
    cnt = b;

    /*@
        loop invariant (b > 0) ==> (res == a + (b - cnt));
        loop invariant (b > 0) ==> (cnt >= 0 && cnt <= b);
        loop invariant (!(b > 0)) ==> ((cnt == b) && (res == a) && (b == b) && (a == a));
        loop invariant b == b;
        loop invariant a == a;
        loop assigns res, cnt;
    */
    while(cnt > 0) {
        cnt = cnt - 1;
        res = res + 1;
    }

    /*@ assert res == a + b; */
}
