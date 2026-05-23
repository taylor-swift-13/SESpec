
/*@
  requires \true;
  assigns \nothing;
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
