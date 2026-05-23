
int foo62_helper1_c13();

/*@
  requires depth >= 10;
  assigns \nothing;
*/
int foo13(int depth);


/*@ logic integer foo13_rec(integer depth) =
      depth < 10 ? foo13_rec(depth + 1) + 1 : 0; */
/*@
  requires depth >= 10;
  decreases depth < 10 ? 10 - depth : 0;
  assigns \nothing;
  ensures \result == 0;
  ensures \result == foo13_rec(depth);
*/
int foo13(int depth) {

    if (depth < 10) return foo13(depth + 1) + 1;
    else return 0;
}
