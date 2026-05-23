#include <limits.h>



/*@ensures year % 400 == 0 && year % 100 == 0 && year % 4 == 0 ==> \result == 1;

ensures year % 400 != 0 && year % 100 == 0 && year % 4 == 0 ==> \result == 0;

ensures year % 100 != 0 && year % 4 == 0 ==> \result == 1;

ensures year % 4 != 0 ==> \result == 0;


assigns \nothing;*/
int stub_A(int year);

/*@requires \true;
ensures \result == 1 <==> ((year % 4 == 0) && (year % 100 != 0 || year % 400 == 0));
ensures \result == 1 <==> ((year % 4 == 0) && ((year % 100 != 0) || (year % 400 == 0)));
ensures \result == 0 <==> !((year % 4 == 0) && (year % 100 != 0 || year % 400 == 0));
ensures \result == 0 <==> !((year % 4 == 0) && ((year % 100 != 0) || (year % 400 == 0)));
assigns \nothing;*/
int stub_B(int year);

/*@requires \true;
ensures \result == 1 <==> ((year % 4 == 0) && (year % 100 != 0 || year % 400 == 0));
ensures \result == 1 <==> ((year % 4 == 0) && ((year % 100 != 0) || (year % 400 == 0)));
ensures \result == 0 <==> !((year % 4 == 0) && (year % 100 != 0 || year % 400 == 0));
ensures \result == 0 <==> !((year % 4 == 0) && ((year % 100 != 0) || (year % 400 == 0)));
assigns \nothing;*/
int check_A_implies_B(int year) {
    return stub_A(year);
}

/*@ensures year % 400 == 0 && year % 100 == 0 && year % 4 == 0 ==> \result == 1;

ensures year % 400 != 0 && year % 100 == 0 && year % 4 == 0 ==> \result == 0;

ensures year % 100 != 0 && year % 4 == 0 ==> \result == 1;

ensures year % 4 != 0 ==> \result == 0;


assigns \nothing;*/
int check_B_implies_A(int year) {
    return stub_B(year);
}
