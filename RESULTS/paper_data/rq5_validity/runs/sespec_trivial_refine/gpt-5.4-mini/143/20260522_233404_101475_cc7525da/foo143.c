int foo143(int n, int time);


/*@
  requires n > 1;
  requires time >= 0;
  assigns \nothing;
  ensures (\old(time) % ((n - 1) * 2) < n ==> \result == (\old(time) % ((n - 1) * 2)) + 1);
  ensures (\old(time) % ((n - 1) * 2) >= n ==> \result == n * 2 - (\old(time) % ((n - 1) * 2)) - 1);
  ensures \result >= 1;
  ensures \result <= n;
*/
int foo143(int n, int time) {

        time %= (n - 1) * 2;
        return time < n ? time + 1 : n * 2 - time - 1;
}