int counter;

int foo25_helper1(int n);

/*@
  requires n >= 0;
           assigns PLACE_HOLDER; 
  ensures PLACE_HOLDER;   
*/
void foo25(int n, int from, int to, int via);


void foo25(int n, int from, int to, int via) {
    if (n == 0) return;
    counter++;
    foo25(n - 1, from, via, to);
    foo25(n - 1, via, to, from);
}