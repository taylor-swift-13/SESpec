
/*@
  requires i >= 0;
  decreases i;
  assigns \nothing;
  ensures \result == 1;
*/
int foo12(int i);


int foo12(int i) {

    if (i == 0) {
      return 1;
    }
    if (i > 0) {
      return foo12(i - 1);
    }
    if (i < 0) {
      return 0;
    }
    return 1;
}
