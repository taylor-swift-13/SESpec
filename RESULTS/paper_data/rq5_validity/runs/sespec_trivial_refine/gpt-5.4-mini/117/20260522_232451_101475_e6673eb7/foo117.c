int foo117(int a, int b, int m);


/*@
  assigns \nothing;
  ensures \result == (m % a == 0 && m % b == 0);
  ensures \result == 1 <==> (m % a == 0 && m % b == 0);
  ensures \result == 0 <==> !(m % a == 0 && m % b == 0);
  ensures \result == 0 || \result == 1;
*/
int foo117(int a, int b, int m) {

        return m % a == 0 && m % b == 0;
}