
    #include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

        

int main1(int a,int n)
/*@

Require emp
Ensure Results(__return)
*/{
 
  int x,y,z;
  
  x=0;
  y=1;
  z=6;
  

 
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv
    ((n@pre<=a@pre) => (n >= n@pre && n <= a + 1)) &&
((n@pre<=a@pre) => (x == (n * n * n))) &&
((n@pre<=a@pre) => (y == (3 * n * n + 3 * n + 1))) &&
((n@pre<=a@pre) => (z == (6 * n + 6))) &&
((!(n@pre<=a@pre)) => ((z == 6)&&(y == 1)&&(x == 0)&&(n == n@pre)&&(a == a@pre))) &&
(a == a@pre)
    */
    
            while(n<=a){
       n=n+1;
       x=x+y;
       y=y+z;
       z=z+6;
  }
  
}