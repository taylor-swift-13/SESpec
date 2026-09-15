int counter;

int foo25_helper1(int n);
void foo25(int n, int from, int to, int via);


/*@ logic integer pow2(integer n) =
      n <= 0 ? 1 : 2 * pow2(n - 1); */
/*@
  requires n >= 0;
  decreases n;
  assigns counter;
  ensures counter == \old(counter) + (pow2(n) - 1);
*/
void foo25(int n, int from, int to, int via) {
    if (n == 0) return;
    counter++;
    foo25(n - 1, from, via, to);
    foo25(n - 1, via, to, from);
}