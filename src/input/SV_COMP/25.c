int foo25_helper1(int n);
void foo25(int n, int from, int to, int via);

int foo25_helper1(int n) {

        if (n == 1) {
          return 1;
        }
        return 2 * (foo25_helper1(n - 1)) + 1;
}

void foo25(int n, int from, int to, int via) {

        if (n == 0) {
          return;
        }

        counter++;
        foo25(n - 1, from, via, to);
        foo25(n - 1, via, to, from);
}
