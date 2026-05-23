#include <limits.h>



/*@ensures n % 5 == 0 && n % 3 != 0 ==> \result == 0 + 5;

ensures n % 5 == 0 && n % 3 == 0 ==> \result == 0 + 3 + 5;

ensures n % 5 != 0 && n % 3 == 0 ==> \result == 0 + 3;

ensures n % 5 != 0 && n % 3 != 0 ==> \result == 0;


assigns \nothing;*/
int stub_A(int n);

/*@ensures \result == 0 || \result == 3 || \result == 5 || \result == 8;
ensures \result == ((n % 3 == 0 ? 3 : 0) + (n % 5 == 0 ? 5 : 0));
ensures (n % 5 == 0) <==> (\result == 5 || \result == 8);
ensures (n % 3 == 0) <==> (\result == 3 || \result == 8);
ensures (n % 3 == 0 && n % 5 == 0) ==> \result == 8;
ensures (n % 3 == 0 && n % 5 != 0) ==> \result == 3;
ensures (n % 3 != 0 && n % 5 == 0) ==> \result == 5;
ensures (n % 3 != 0 && n % 5 != 0) ==> \result == 0;
ensures (\result == 8) <==> (n % 3 == 0 && n % 5 == 0);
ensures (\result == 5) <==> (n % 3 != 0 && n % 5 == 0);
ensures (\result == 3) <==> (n % 3 == 0 && n % 5 != 0);
ensures (\result == 0) <==> (n % 3 != 0 && n % 5 != 0);
ensures (\result == 0 || \result == 3 || \result == 5 || \result == 8);
assigns \nothing;*/
int stub_B(int n);

/*@ensures \result == 0 || \result == 3 || \result == 5 || \result == 8;
ensures \result == ((n % 3 == 0 ? 3 : 0) + (n % 5 == 0 ? 5 : 0));
ensures (n % 5 == 0) <==> (\result == 5 || \result == 8);
ensures (n % 3 == 0) <==> (\result == 3 || \result == 8);
ensures (n % 3 == 0 && n % 5 == 0) ==> \result == 8;
ensures (n % 3 == 0 && n % 5 != 0) ==> \result == 3;
ensures (n % 3 != 0 && n % 5 == 0) ==> \result == 5;
ensures (n % 3 != 0 && n % 5 != 0) ==> \result == 0;
ensures (\result == 8) <==> (n % 3 == 0 && n % 5 == 0);
ensures (\result == 5) <==> (n % 3 != 0 && n % 5 == 0);
ensures (\result == 3) <==> (n % 3 == 0 && n % 5 != 0);
ensures (\result == 0) <==> (n % 3 != 0 && n % 5 != 0);
ensures (\result == 0 || \result == 3 || \result == 5 || \result == 8);
assigns \nothing;*/
int check_A_implies_B(int n) {
    return stub_A(n);
}

/*@ensures n % 5 == 0 && n % 3 != 0 ==> \result == 0 + 5;

ensures n % 5 == 0 && n % 3 == 0 ==> \result == 0 + 3 + 5;

ensures n % 5 != 0 && n % 3 == 0 ==> \result == 0 + 3;

ensures n % 5 != 0 && n % 3 != 0 ==> \result == 0;


assigns \nothing;*/
int check_B_implies_A(int n) {
    return stub_B(n);
}
