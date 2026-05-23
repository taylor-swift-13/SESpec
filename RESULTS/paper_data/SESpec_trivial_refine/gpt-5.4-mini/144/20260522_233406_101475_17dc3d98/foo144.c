int foo144(int n, int time);


/*@
  requires n > 1;
  requires time >= 0;
  assigns \nothing;
  ensures \result == ((((\old(time) % (n - 1)) * 2) < n)
                      ? (((\old(time) % (n - 1)) * 2) + 1)
                      : ((n * 2) - ((\old(time) % (n - 1)) * 2) - 1));
  ensures (((\old(time) % (n - 1)) * 2) < n) ==> (\result == ((\old(time) % (n - 1)) * 2) + 1);
  ensures (((\old(time) % (n - 1)) * 2) >= n) ==> (\result == (n * 2) - ((\old(time) % (n - 1)) * 2) - 1);
  ensures \result % 2 == 1;
  ensures \result > 0;
*/
int foo144(int n, int time) {
  time = time % (n - 1) * 2;
  if (time < n) {
    return time + 1;
  }
  return n * 2 - time - 1;
}