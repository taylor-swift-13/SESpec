#include <limits.h>



/*@assigns \nothing;
  ensures \true;
  ensures \true;
  ensures \true;*/
double stub_A(double celsius);

/*@requires \true;
requires \is_finite(celsius);
assigns \nothing;*/
double stub_B(double celsius);

/*@requires \true;
requires \is_finite(celsius);
assigns \nothing;*/
double check_A_implies_B(double celsius) {
    return stub_A(celsius);
}

/*@assigns \nothing;
  ensures \true;
  ensures \true;
  ensures \true;*/
double check_B_implies_A(double celsius) {
    return stub_B(celsius);
}
