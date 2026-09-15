/*@ 
  requires i >= 0;
  assigns \nothing;
  terminates \true;
  ensures \result == 1;
*/
int recursion(int i);

int recursion(int i) {

    if (i == 0) {
      return 1;
    }
    if (i > 0) {
      return recursion(i - 1);
    }
    if (i < 0) {
      return 0;
    }
    return 1;
}
