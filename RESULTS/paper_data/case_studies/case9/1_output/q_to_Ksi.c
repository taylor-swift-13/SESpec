#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

void q_to_Ksi(int *Ksi, int *q)

/*@
With Ksi_l q_l
Require store_int_ptr(Ksi) && store_int_ptr(q)
Ensure emp
*/{
    int x = q[0];
    int y = q[1];
    int z = q[2];
    int w = q[3];

    Ksi[0] =  w;  Ksi[1]  = -z;  Ksi[2]  =  y;
    Ksi[3] =  z;  Ksi[4]  =  w;  Ksi[5]  = -x;
    Ksi[6] = -y;  Ksi[7]  =  x;  Ksi[8]  =  w;
    Ksi[9] = -x;  Ksi[10] = -y;  Ksi[11] = -z;
    return;
}