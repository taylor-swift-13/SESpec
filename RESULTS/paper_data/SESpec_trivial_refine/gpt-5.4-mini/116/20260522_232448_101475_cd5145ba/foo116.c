int foo116(int a, int b, int factor);


/*@
  assigns \nothing;
  ensures \result == 1 <==> (a % factor == 0 && b % factor == 0);
  ensures \result == 0 <==> (a % factor != 0 || b % factor != 0);
  ensures \result == 0 || \result == 1;
  ensures a % factor == 0 ==> (b % factor == 0 <==> \result == 1);
*/
int foo116(int a, int b, int factor) {

        if (a % factor != 0) {
            return 0;
        }
        if (b % factor != 0) {
            return 0;
        }
        return 1;
}