

/*@
  requires i >= 0;
           assigns PLACE_HOLDER;   
  ensures PLACE_HOLDER; 
    ensures \result == PLACE_HOLDER_RESULT;  
*/
int foo41(int i);


/*@ logic integer foo41_result(integer i) =
      i == 0 ? 1 : (i > 0 ? foo41_result(i - 1) : 0); */
/*@
  requires i >= 0;
  decreases i;
  assigns \nothing;
  ensures \result == foo41_result(i);
*/
int foo41(int i) {

    if (i == 0) {
      return 1;
    }
    if (i > 0) {
      return foo41(i - 1);
    }
    if (i < 0) {
      return 0;
    }
    return 1;
}