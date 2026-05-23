
int counter;

int foo25_helper1_c4(int n);

/*@ logic integer pow2(integer n) = n <= 0 ? 1 : 2 * pow2(n - 1); */

/* Prototype without broken contract */
void foo4(int n, int from, int to, int via);

/*@
  requires n >= 0;
  decreases n;
  assigns counter;
  ensures counter == \old(counter) + (pow2(n) - 1);
  ensures (n == 0) <==> (counter == \old(counter));
  ensures n == \old(n) && from == \old(from) && to == \old(to) && via == \old(via);
  ensures n >= 0;
*/
void foo4(int n, int from, int to, int via) {
    if (n == 0) return;
    counter++;
    foo4(n - 1, from, via, to);
    foo4(n - 1, via, to, from);
}
