#include <limits.h>



/*@requires s <= 0;
  assigns \nothing;
  ensures \result >= 0;
  ensures \forall integer l, integer b; 1 <= l <= s && 1 <= b && b <= s - l + 1 ==> \result >= l * b * (s - l - b);
  ensures (\exists integer l, integer b; 1 <= l <= s && 1 <= b && b <= s - l + 1 && l * b * (s - l - b) > 0) ==> \result > 0;*/
int stub_A(int s);

/*@
  requires \true;
  assigns \nothing;
  ensures \true;
*/
int stub_B(int s);

/*@
  requires \true;
  assigns \nothing;
  ensures \true;
*/
int check_A_implies_B(int s) {
    return stub_A(s);
}

/*@requires s <= 0;
  assigns \nothing;
  ensures \result >= 0;
  ensures \forall integer l, integer b; 1 <= l <= s && 1 <= b && b <= s - l + 1 ==> \result >= l * b * (s - l - b);
  ensures (\exists integer l, integer b; 1 <= l <= s && 1 <= b && b <= s - l + 1 && l * b * (s - l - b) > 0) ==> \result > 0;*/
int check_B_implies_A(int s) {
    return stub_B(s);
}
