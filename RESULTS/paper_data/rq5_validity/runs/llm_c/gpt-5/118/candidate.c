int isCommonMultiple(int a, int b, int m);

/*@ 
  requires a != 0 && b != 0;
  assigns \nothing;

  behavior common:
    assumes m % a == 0 && m % b == 0;
    ensures \result == 1;

  behavior not_common:
    assumes m % a != 0 || m % b != 0;
    ensures \result == 0;

  complete behaviors common, not_common;
  disjoint behaviors common, not_common;

  ensures 0 <= \result <= 1;
  ensures (\result == 1) <==> (m % a == 0 && m % b == 0);
*/
int isCommonMultiple(int a, int b, int m) {

        if(m % a != 0) {
            /*@ assert m % a != 0; */
            return 0;
        }
        /*@ assert m % a == 0; */
        if(m % b != 0) {
            /*@ assert m % a == 0 && m % b != 0; */
            return 0;
        }
        /*@ assert m % a == 0 && m % b == 0; */
        return 1;
}
