int counter;

int foo25_helper1_c4(int n);
void foo4(int n, int from, int to, int via);

int foo25_helper1_c4(int n) {
    if (n == 1) return 1;
    return 2 * foo25_helper1_c4(n - 1) + 1;
}

void foo4(int n, int from, int to, int via) {
    if (n == 0) return;
    counter++;
    foo4(n - 1, from, via, to);
    foo4(n - 1, via, to, from);
}
