
/*@
  logic integer mccarthy91(integer n) =
    n > 100 ? n - 10 : mccarthy91(mccarthy91(n + 11));
*/

/*@
  requires \true;
  decreases n;
  assigns \nothing;
  ensures \result == mccarthy91(n);
*/
int foo5(int n);


int foo5(int n) {

    if (n > 100) return n - 10;
    else return foo5(foo5(n + 11));
}
