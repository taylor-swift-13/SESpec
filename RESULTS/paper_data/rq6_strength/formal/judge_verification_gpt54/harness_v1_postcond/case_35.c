#include <limits.h>



/*@assigns \nothing;
  ensures \result == ((((char)(input * 2 + 1) | 2) & 3) == 3);
  ensures \result == 0 || \result == 1;*/
int stub_A(int input);

/*@requires -64 <= input <= 63;
ensures \result == 1 || \result == 0;
ensures \result == 1 <==> ((((char)(input * 2 + 1)) | 2) & 3) == 3;
ensures \result == (((((char)(input * 2 + 1)) | 2) & 3) == 3);
assigns \nothing;*/
int stub_B(int input);

/*@requires -64 <= input <= 63;
ensures \result == 1 || \result == 0;
ensures \result == 1 <==> ((((char)(input * 2 + 1)) | 2) & 3) == 3;
ensures \result == (((((char)(input * 2 + 1)) | 2) & 3) == 3);
assigns \nothing;*/
int check_A_implies_B(int input) {
    return stub_A(input);
}

/*@assigns \nothing;
  ensures \result == ((((char)(input * 2 + 1) | 2) & 3) == 3);
  ensures \result == 0 || \result == 1;*/
int check_B_implies_A(int input) {
    return stub_B(input);
}
