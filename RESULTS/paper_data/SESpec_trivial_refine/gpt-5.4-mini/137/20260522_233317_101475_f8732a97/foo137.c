int foo137(int a, int b, int factor);


/*@
  assigns \nothing;
  ensures \result == ((a % factor != 0) || (b % factor != 0));
  ensures \result == 0 <==> (a % factor == 0 && b % factor == 0);
  ensures \result != 0 <==> (a % factor != 0 || b % factor != 0);
  ensures factor != 0 ==> (\result == 0 || \result == 1);
*/
int foo137(int a, int b, int factor) {
        return a % factor != 0 || b % factor != 0;
}