
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
  

  while(n<=a){
       n=n+1;
       x=x+y;
       y=y+z;
       z=z+6;
  }
  
}