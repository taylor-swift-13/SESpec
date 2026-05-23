int foo42_c12(int i);


/*@ logic integer foo42_c12_spec(integer i) =
      i < 0 ? 0 : 1; */
/*@
  decreases i >= 0 ? i : 0;
  assigns \nothing;
  ensures \result == foo42_c12_spec(i);
*/
int foo42_c12(int i) {

    if (i == 0) {
      return 1;
    }
    if (i > 0) {
      return foo42_c12(i - 1);
    }
    if (i < 0) {
      return 0;
    }
    return 1;
}