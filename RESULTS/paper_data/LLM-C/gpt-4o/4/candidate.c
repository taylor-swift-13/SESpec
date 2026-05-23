int counter;

/*@
    requires n >= 1;
    ensures \result == (1 << n) - 1; // The number of moves in Tower of Hanoi is 2^n - 1
    assigns \nothing;
*/
int hanoi(int n) {
    if (n == 1) return 1;
    return 2 * hanoi(n - 1) + 1;
}

/*@
    requires n >= 0;
    requires from >= 0 && to >= 0 && via >= 0;
    ensures counter == \old(counter) + hanoi(n); // Counter is incremented by the number of moves
    assigns counter;
*/
void applyHanoi(int n, int from, int to, int via) {
    if (n == 0) return;
    counter++;
    applyHanoi(n - 1, from, via, to);
    applyHanoi(n - 1, via, to, from);
}
