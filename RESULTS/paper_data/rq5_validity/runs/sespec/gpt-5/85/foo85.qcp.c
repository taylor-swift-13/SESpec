#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

void foo85(int a,int b)
/*@

Require emp
Ensure emp
*/{

    int x=a;
    int y=b;
    int z=0;

   
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    (y >= 0) &&
    (x >= 0 => z <= a@pre * b@pre) &&
    (b@pre >= 0 => 0 <= z && z <= a@pre * b@pre) &&
    ((y == 0) => (z == a@pre * b@pre)) &&
    ((y > 0) => (z < a@pre * b@pre || x == 0)) &&
    (exists (k:Z), k >= 0 && y == k) &&
    ((b@pre!=0) => (z + x * y == a@pre * b@pre)) &&
    ((b@pre!=0) => (y >= 0)) &&
    ((b@pre!=0) => (z >= 0 || z <= a@pre * b@pre)) &&
    ((!(b@pre!=0)) => ((z == 0)&&(y == b@pre)&&(x == a@pre)&&(b == b@pre)&&(a == a@pre))) &&
    (b == b@pre) &&
    (a == a@pre)
    */
    
            while(y!=0) {

     if (y%2 ==1 ){
          z = z+x;
          y = y-1;
     }
     x = 2*x;
     y = y/2;
    }

}