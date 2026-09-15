int counter;

/*@
    requires 1 <= n <= 30;
    assigns \nothing;
    ensures \result == (1 << n) - 1;
    decreases n;
*/
int hanoi(int n);
void applyHanoi(int n, int from, int to, int via);

/*@
    requires 1 <= n <= 30;
    assigns \nothing;
    ensures \result == (1 << n) - 1;
    decreases n;
*/
int hanoi(int n) {
    if (n == 1) return 1;
    return 2 * hanoi(n - 1) + 1;
}

/*@
    requires 0 <= n <= 30;
    assigns counter;
    ensures counter == \old(counter) + ((1 << n) - 1);
    decreases n;
*/
void applyHanoi(int n, int from, int to, int via) {
    if (n == 0) return;
    counter++;
    applyHanoi(n - 1, from, via, to);
    applyHanoi(n - 1, via, to, from);
}
