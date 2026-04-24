int hanoi(int n);
void applyHanoi(int n, int from, int to, int via);

int hanoi(int n) {

        if (n == 1) {
          return 1;
        }
        return 2 * (hanoi(n - 1)) + 1;
}

void applyHanoi(int n, int from, int to, int via) {

        if (n == 0) {
          return;
        }

        counter++;
        applyHanoi(n - 1, from, via, to);
        applyHanoi(n - 1, via, to, from);
}
