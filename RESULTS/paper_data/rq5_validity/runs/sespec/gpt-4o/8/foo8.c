int foo32_helper1_c8(int n, int m);
int foo32_helper2_c8(int n, int m);
int foo32_helper3_c8(int n);

/*@
  requires n >= 0;
  requires m >= 0;
           assigns PLACE_HOLDER;   
  ensures PLACE_HOLDER; 
    ensures \result == PLACE_HOLDER_RESULT;  
*/
int foo8(int n, int m);


/*@
  requires n >= 0;
  requires m >= 0;
  assigns \nothing;
  ensures n <= 1 ==> \result == 0;
  ensures n == 2 ==> \result == 1;
  ensures n > 2 && m <= 1 ==> \result == 1;
  ensures n > 2 && m > 1 && foo32_helper2_c8(n, m) == 0 ==> \result == 0;
  ensures n > 2 && m > 1 && foo32_helper2_c8(n, m) != 0 ==> \result == foo8(n, m - 1);
  decreases m; 
*/
int foo8(int n, int m) {

    if (n <= 1) {
      return 0; // 0
    } else if (n == 2) {
      return 1; // 1
    } else {
      if (m <= 1) {
        return 1; // 1
      } else {
        if (foo32_helper2_c8(n, m) == 0) {
          return 0; // 0
        }
        return foo8(n, m - 1);
      }
    }
}