int f(int n);

/*@ 
  @ requires \true;
  @ assigns \nothing;
  @ decreases (n <= 100) ? 2 * (101 - n) : 0;
  @
  @ behavior large:
  @   assumes n > 100;
  @   ensures \result == n - 10;
  @
  @ behavior small:
  @   assumes n <= 100;
  @   ensures \result == 91;
  @
  @ complete behaviors large, small;
  @ disjoint  behaviors large, small;
  @*/
int f(int n) {

    if (n > 100) return n - 10;
    else return f(f(n + 11));
}
