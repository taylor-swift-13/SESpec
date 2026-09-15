int foo32_helper1_c8(int n, int m);
int foo32_helper2_c8(int n, int m);
int foo32_helper3_c8(int n);

/*@
  requires n >= 0 || m >= 0;
*/

/*@
  requires n >= 0 || m >= 0;
*/

/*@
  requires n >= 0 || m >= 0;
*/

/*@
  requires n >= 0 || m >= 0;
           assigns PLACE_HOLDER;   
  ensures PLACE_HOLDER; 
    ensures \result == PLACE_HOLDER_RESULT;  
*/
int foo8(int n, int m);

int foo32_helper1_c8(int n, int m);

/*@
  requires n >= 0 || m >= 0;
  assigns \nothing;
*/
int foo32_helper2_c8(int n, int m);
int foo32_helper3_c8(int n);
int foo8(int n, int m);

/*@ logic integer foo32_helper2_c8_model(integer n, integer m) =
      m < 0 ? foo32_helper2_c8_model(n, -m) :
      n < 0 ? foo32_helper2_c8_model(-n, m) :
      m == 0 ? 0 :
      n == 0 ? 1 :
      foo32_helper2_c8_model(n - m, m); */
/*@
  requires n >= 0 || m >= 0;
  decreases (n < 0 ? -n : n) + (m < 0 ? -m : m);
  assigns \nothing;
  ensures \result == foo32_helper2_c8_model(n, m);
*/
int foo32_helper2_c8(int n, int m) {

    if (m < 0) {
      return foo32_helper2_c8(n, -m);
    }
    if (n < 0) {
      return foo32_helper2_c8(-n, m);
    }
    if (m == 0) {
      return 0;
    }
    if (n == 0) {
      return 1;
    }
    return foo32_helper2_c8(n - m, m);
}


/*@
  requires n >= 0 || m >= 0;
  decreases m < 0 ? -m : m;
  assigns \nothing;
  ensures (n <= 1 ==> \result == 0) &&
          (n == 2 ==> \result == 1) &&
          (n > 2 && m <= 1 ==> \result == 1) &&
          (n > 2 && m > 1 && foo32_helper2_c8(n, m) == 0 ==> \result == 0) &&
          (n > 2 && m > 1 && foo32_helper2_c8(n, m) != 0 ==> \result == foo8(n, m - 1));
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