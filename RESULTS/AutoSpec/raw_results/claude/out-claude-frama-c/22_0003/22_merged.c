int sum(char n) {
    int s = 0;
    char k = 0;

    /*@
    loop invariant s == (k * (k - 1)) / 2;
    loop invariant k <= n + 1;
    loop invariant 0 <= k;
    loop assigns s;
    loop assigns k;
    ```c;
    ```;
    Looking at the pattern from the examples, I need to generate loop invariants for the `sum` function's while loop.;
    Here are the loop invariants:;
    Analyzing the loop:;
    - `s` accumulates the sum of values from 0 to k-1;
    - `k` ranges from 0 to n (inclusive);
    - The loop terminates when k > n;
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