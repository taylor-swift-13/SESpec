int foo62_helper1_c13();

/*@
  requires depth >= 0;
           assigns PLACE_HOLDER;   
  ensures PLACE_HOLDER; 
    ensures \result == PLACE_HOLDER_RESULT;  
  decreases 10 - depth;
*/
int foo13(int depth);


/*@ 
  logic integer foo13_logic(integer depth) =
    depth >= 10 ? 0 : 10 - depth;
*/
/*@
  requires depth >= 0;
  decreases 10 - depth;
  assigns \nothing;
  ensures \result == foo13_logic(depth);
*/
int foo13(int depth) {
    if (depth < 10) 
        return foo13(depth + 1) + 1;
    else 
        return 0;
}