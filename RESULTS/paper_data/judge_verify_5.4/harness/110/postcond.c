#include <limits.h>

/*@ logic integer abs_int(integer x) = x < 0 ? -x : x; */

/*@ ensures (\old(num1) == 0 && \old(num2) == 0) ==> \result == -1;
  ensures (\old(num1) != 0 || \old(num2) != 0) && (abs_int(\old(num1)) == 0 || abs_int(\old(num2)) == 0) ==> 
            \result == (abs_int(\old(num1)) > abs_int(\old(num2)) ? abs_int(\old(num1)) : abs_int(\old(num2)));
  ensures (\old(num1) != 0 || \old(num2) != 0) && abs_int(\old(num1)) != 0 && abs_int(\old(num2)) != 0 ==> 
            (1 <= \result && \result <= abs_int(\old(num1)) && 1 <= \result && \result <= abs_int(\old(num2)));
  assigns \nothing; */
int stub_A(int num1, int num2);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int stub_B(int num1, int num2);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \true;
 */
int check_A_implies_B(int num1, int num2) {
    return stub_A(num1, num2);
}

/*@ ensures (\old(num1) == 0 && \old(num2) == 0) ==> \result == -1;
  ensures (\old(num1) != 0 || \old(num2) != 0) && (abs_int(\old(num1)) == 0 || abs_int(\old(num2)) == 0) ==> 
            \result == (abs_int(\old(num1)) > abs_int(\old(num2)) ? abs_int(\old(num1)) : abs_int(\old(num2)));
  ensures (\old(num1) != 0 || \old(num2) != 0) && abs_int(\old(num1)) != 0 && abs_int(\old(num2)) != 0 ==> 
            (1 <= \result && \result <= abs_int(\old(num1)) && 1 <= \result && \result <= abs_int(\old(num2)));
  assigns \nothing; */
int check_B_implies_A(int num1, int num2) {
    return stub_B(num1, num2);
}
