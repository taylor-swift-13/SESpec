int passPillow(int n, int time);

/*@ 
  requires n >= 2;
  requires time >= 0;
  assigns \nothing;
  ensures 1 <= \result <= n;
  ensures \let m = (n - 1) * 2;
          \let t = \old(time) % m;
          \result == (t < n ? t + 1 : n * 2 - t - 1);
*/
int passPillow(int n, int time) {

        time %= (n - 1) * 2;
        /*@ assert 0 <= time < (n - 1) * 2; */
        return time < n ? time + 1 : n * 2 - time - 1;
}
