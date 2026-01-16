int sum(char n) {
    int s = 0;
    char k = 0;

    /*@
    loop invariant 0 <= k <= n + 1;
    loop invariant s == (k * (k - 1)) / 2;
    loop assigns s, k;
    */
    while(k <= n) {    
        s = s + (int)k;
        k = k + 1;
    }
    return (int)s;
}

int doo3() {
    int s = sum(5);
    // @ assert s == 15;
}