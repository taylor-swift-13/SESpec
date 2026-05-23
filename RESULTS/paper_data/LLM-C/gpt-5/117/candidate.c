int isCommonMultiple(int a, int b, int m);

/*@ 
  predicate is_common_multiple_of(int a, int b, int m) =
    a != 0 && b != 0 && (m % a == 0) && (m % b == 0);
*/

/*@ 
  requires a != 0 && b != 0;
  assigns \nothing;
  ensures (\result == 0) || (\result == 1);
  ensures (\result != 0) <=> is_common_multiple_of(a, b, m);
  behavior is_mult:
    assumes is_common_multiple_of(a, b, m);
    ensures \result == 1;
  behavior not_mult:
    assumes !is_common_multiple_of(a, b, m);
    ensures \result == 0;
  complete behaviors is_mult, not_mult;
  disjoint behaviors is_mult, not_mult;
*/
int isCommonMultiple(int a, int b, int m) {

        return m % a == 0 && m % b == 0;
}
