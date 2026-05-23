



/*@
  assigns \nothing;
  ensures diff < 1 ==> \result == 0;
  ensures diff >= 1 ==> \result ==
    (((diff * (diff + 1)) / 2) * ((diff * (diff + 1)) / 2))
    - ((diff * (diff + 1)) / 2);
  ensures \result >= 0;
*/
int foo329(int diff) {
  if (diff < 1) {
    return 0;
  } else {
    int t = (diff * (diff + 1)) / 2;
    return t * t - t;
  }
}
