/*@ global invariant counter_nonneg: counter >= 0; */
int counter;

int hanoi(int n);
void applyHanoi(int n, int from, int to, int via);

/*@ 
  requires n >= 1;
  assigns \nothing;
  ensures \result >= 1;
  ensures \result == (1 << n) - 1;
*/
int hanoi(int n) {
    if (n == 1) return 1;
    return 2 * hanoi(n - 1) + 1;
}

/*@ 
  requires n >= 0;
  assigns counter;
  ensures counter == \old(counter) + hanoi(n);
*/
void applyHanoi(int n, int from, int to, int via) {
    if (n == 0) return;
    counter++;
    applyHanoi(n - 1, from, via, to);
    applyHanoi(n - 1, via, to, from);
}
