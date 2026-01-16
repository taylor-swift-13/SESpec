int sum(char n) {
    int s = 0;
    char k = 0;

    /*@
    Looking at the pattern from the examples, I need to generate loop invariants for the `sum` function's while loop.
    
    Analyzing the loop:
    - `k` ranges from 0 to n (inclusive)
    - `s` accumulates the sum of values from 0 to k-1
    - The loop terminates when k > n
    
    Here are the loop invariants:
    
    ```c
    loop invariant 0 <= k <= n + 1;
    loop invariant s == (k * (k - 1)) / 2;
    loop assigns k;
    loop assigns s;
    ```
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