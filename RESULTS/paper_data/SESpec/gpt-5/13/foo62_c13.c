int foo62_helper1_c13();
int foo62_c13(int depth);


/*@ logic integer foo62_c13_spec(integer depth) =
      depth >= 10 ? 0 : 10 - depth; */
/*@
  decreases (\max(0, 10 - depth));
  assigns \nothing;
  ensures \result == foo62_c13_spec(depth);
*/
int foo62_c13(int depth) {

    if (depth < 10) return foo62_c13(depth + 1) + 1;
    else return 0;
}