
/*@ predicate nonnegative(integer x) = x >= 0; */
        
/*@
  assigns \nothing;
  ensures count <= 0 ==> \result == 0;
  ensures count > 0 ==> \result > 0;
  ensures count > 0 ==> \result <= 4 * count * count;
  ensures \result >= 0;
*/
int foo313(int count) {
  if (count <= 0) {
    return 0;
  }

  return 1;
}
