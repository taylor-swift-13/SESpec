
/*@ logic integer foo40_result(integer i) =
      i <= 0 ? 1 : foo40_result(i - 1); */

/*@
  requires i >= 0;
  decreases i;
  assigns \nothing;
  ensures \result == foo40_result(i);
  ensures i == 0 ==> \result == 1;
  ensures i > 0 ==> \result == foo40_result(i - 1);
*/
int foo40(int i);

/*@
  requires i >= 0;
  decreases i;
  assigns \nothing;
  ensures \result == foo40_result(i);
  ensures i == 0 ==> \result == 1;
  ensures i > 0 ==> \result == foo40_result(i - 1);
*/
int foo40(int i) {

    if (i == 0) {
      return 1;
    }
    if (i > 0) {
      return foo40(i - 1);
    }
    if (i < 0) {
      return 0;
    }
    return 1;
}
