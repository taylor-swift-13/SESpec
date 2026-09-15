

/*@
  requires i >= 0;
           assigns PLACE_HOLDER;   
  ensures PLACE_HOLDER; 
    ensures \result == PLACE_HOLDER_RESULT;  
*/
int foo40(int i);


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