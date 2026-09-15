
/*@ 
  logic integer foo_logic(integer i) =
      i <= 0 ? (i == 0 ? 1 : 0) : foo_logic(i - 1);
*/

/*@
  requires i >= 0;
  decreases i;
  assigns \nothing;
  ensures i == 0 ==> \result == 1;
  ensures i > 0 ==> \result == foo_logic(i);
  ensures i < 0 ==> \result == 0;
*/
int foo10(int i) {
    if (i == 0) {
        return 1;
    }
    if (i > 0) {
        return foo10(i - 1);
    }
    if (i < 0) {
        return 0;
    }
    return 1;
}
