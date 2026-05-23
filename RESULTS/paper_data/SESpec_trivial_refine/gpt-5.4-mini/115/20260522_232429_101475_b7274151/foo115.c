int foo115(int a, int b, int factor);


/*@
  assigns \nothing;
  ensures \result == (a % factor == 0 && b % factor == 0);
  ensures \result == 1 <==> (a % factor == 0 && b % factor == 0);
  ensures \result == 0 <==> !(a % factor == 0 && b % factor == 0);
*/
int foo115(int a, int b, int factor) {

        return a % factor == 0 && b % factor == 0;
}