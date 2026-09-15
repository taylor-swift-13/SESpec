
int counter;

int foo25_helper1(int n);

/*@
  logic integer hanoi_calls(integer n) =
    n <= 0 ? 0 : 2 * hanoi_calls(n - 1) + 1;
*/

/*@
  requires n >= 0;
  decreases n;
  assigns counter;
  ensures counter == \old(counter) + hanoi_calls(n);
*/
void foo25(int n, int from, int to, int via);


void foo25(int n, int from, int to, int via) {
    if (n == 0) return;
    counter++;
    foo25(n - 1, from, via, to);
    foo25(n - 1, via, to, from);
}
