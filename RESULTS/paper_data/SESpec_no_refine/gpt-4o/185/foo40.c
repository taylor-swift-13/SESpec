

/*@
  requires i >= -2147483648 && i <= 2147483647;
           assigns PLACE_HOLDER;   
  ensures PLACE_HOLDER; 
    ensures \result == PLACE_HOLDER_RESULT;  
*/
int foo40(int i);


/*@ 
  logic integer foo40_logic(integer i) =
    (i == 0) ? 1 :
    (i > 0) ? foo40_logic(i - 1) :
    (i < 0) ? 0 : 1;
*/
/*@
  requires i >= -2147483648 && i <= 2147483647;
  decreases (i > 0) ? i : 0;
  assigns \nothing;
  ensures \result == foo40_logic(i);
*/
int foo40(int i) {
    if (i == 0) {
      return 1;
    }
    if (i > 0) {
      return foo40(i - 1);
    }
    if (i < 0) {
      return 0;
    }
    return 1;
}