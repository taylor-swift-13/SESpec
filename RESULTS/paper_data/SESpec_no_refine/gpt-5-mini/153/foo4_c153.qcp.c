#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

#include <stdlib.h>

int foo4_c153(int n, int k);

int foo4_c153(int n, int k) 
/*@

Require emp
Ensure Results(__return)
*/{

        int *a = (int *)malloc(sizeof(int) * (n));
int a_len = n;
        int *b = (int *)malloc(sizeof(int) * (n));
int b_len = n;
        int i,count=0;
       
  /*@ Print user assertion at number LoopEntry_0*/ 
/*@ Inv emp */ /*0*/ 
 for(i=0;i<n;i++){
            a[i]=i+1;
        }
       
  /*@ Print user assertion at number LoopEntry_1*/ 
/*@ Inv emp */ /*1*/ 
 for(i=0;i<n;i++){
            b[i]=a[i];
            if(a[i]%2!=0){
                count++;
                if(count==k){
                    return a[i];
                }
            }
        }
       
  /*@ Print user assertion at number LoopEntry_2*/ 
/*@ Inv emp */ /*2*/ 
 for(i=0;i<n;i++){
            b[i]=a[i];
            if(a[i]%2==0){
                count++;
                if(count==k){
                    return a[i];
                }
            }
        }
        return 0;
}