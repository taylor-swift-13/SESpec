
/*@
  requires \true;
  assigns \nothing;
  ensures \result == 1 <==> i >= 0;
  ensures \result == 0 <==> i < 0;
*/
int foo10(int i);

/*@ logic integer foo10_rec(integer i) =
      i <= 0 ? (i == 0 ? 1 : 0) : foo10_rec(i - 1); */

/*@
  requires \true;
  decreases i > 0 ? i : 0;
  assigns \nothing;
  ensures \result == foo10_rec(i);
  ensures i >= 0 ==> \result == 1;
  ensures i < 0 ==> \result == 0;
  ensures \result == 1 <==> i >= 0;
*/
int foo10(int i) {
  if (i == 0) {
    return 1;
  }
  if (i > 0) {
    return foo10(i - 1);
  }
  return 0;
}
