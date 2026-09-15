
int counter;

/*@ 
  logic integer hanoi_steps(integer n) = 
    n <= 0 ? 0 : 2 * hanoi_steps(n - 1) + 1;
*/

/*@
  requires n >= 0;
  assigns counter;
  ensures counter == \old(counter) + hanoi_steps(n);
*/
void foo25(int n, int from, int to, int via);

/*@
  requires n >= 0;
  decreases n;
  assigns counter;
  ensures counter == \old(counter) + hanoi_steps(n);
*/
void foo25(int n, int from, int to, int via) {
    if (n == 0) return;
    counter++;
    foo25(n - 1, from, via, to);
    foo25(n - 1, via, to, from);
}
