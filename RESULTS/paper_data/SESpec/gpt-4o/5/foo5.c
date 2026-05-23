
/*@ 
  logic integer foo5_logic(integer n) =
      n > 100 ? n - 10 : foo5_logic(foo5_logic(n + 11));
*/

/*@
  requires n >= 0;
  decreases n > 100 ? 0 : 101 - n;
  assigns \nothing;
  ensures \result == foo5_logic(n);
*/
int foo5(int n);


/*@
  requires n >= 0;
  decreases n > 100 ? 0 : 101 - n;
  assigns \nothing;
  ensures \result == foo5_logic(n);
*/
int foo5(int n) {
    if (n > 100) return n - 10;
    else return foo5(foo5(n + 11));
}
