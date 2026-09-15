
/*@
  requires i >= 0;
  decreases i;
  assigns \nothing;
  ensures \result == 1;
*/
int foo41(int i);


int foo41(int i) {

    if (i == 0) {
      return 1;
    }
    if (i > 0) {
      return foo41(i - 1);
    }
    if (i < 0) {
      return 0;
    }
    return 1;
}
