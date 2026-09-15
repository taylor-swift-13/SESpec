int foo138(int a, int b, int factor);


/*@
  requires factor != 0;
  assigns \nothing;
  ensures (\result == 1) <==> (a % factor != 0 || b % factor != 0);
  ensures (\result == 0) <==> (a % factor == 0 && b % factor == 0);
  ensures \result == 0 || \result == 1;
*/
int foo138(int a, int b, int factor) {

        if(a % factor != 0) {
            return 1;
        }
        if(b % factor != 0) {
            return 1;
        }
        return 0;
}