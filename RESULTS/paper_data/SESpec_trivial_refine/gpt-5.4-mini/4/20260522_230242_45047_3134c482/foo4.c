
int counter;

int foo25_helper1_c4(int n);

/*@
  requires n >= 0;
  assigns counter;
*/
void foo4(int n, int from, int to, int via);

void foo4(int n, int from, int to, int via) {
    if (n == 0) return;
    counter++;
    foo4(n - 1, from, via, to);
    foo4(n - 1, via, to, from);
}
