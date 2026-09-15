
int foo62_helper1_c13();

/*@
  requires \true;
  assigns \nothing;
*/
int foo13(int depth);

/*@
  requires \true;
  decreases 10 - depth;
  assigns \nothing;
  ensures depth < 10 ==> \result == 10 - depth;
  ensures depth >= 10 ==> \result == 0;
  ensures \result >= 0;
  ensures \result == (depth < 10 ? 10 - depth : 0);
*/
int foo13(int depth) {
    if (depth < 10) return foo13(depth + 1) + 1;
    else return 0;
}
