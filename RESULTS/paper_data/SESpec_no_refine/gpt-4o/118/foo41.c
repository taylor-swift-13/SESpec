

/*@
  requires i >= 0;
           assigns PLACE_HOLDER;   
  ensures PLACE_HOLDER; 
    ensures \result == PLACE_HOLDER_RESULT;  
*/
int foo41(int i);


/*@ logic integer foo41_logic(integer i) =
      i == 0 ? 1 : foo41_logic(i - 1);
*/
/*@
  requires i >= 0;
  decreases i;
  assigns \nothing;
  ensures \result == foo41_logic(i);
*/
int foo41(int i) {
    if (i == 0) {
        return 1;
    }
    if (i > 0) {
        return foo41(i - 1);
    }
    if (i < 0) {
        return 0; // Dead code due to precondition
    }
    return 1; // Unreachable code
}