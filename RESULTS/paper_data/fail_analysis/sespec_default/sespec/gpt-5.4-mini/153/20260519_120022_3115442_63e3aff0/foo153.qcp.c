#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

#include <stdlib.h>

int foo153(int n, int k);

int foo153(int n, int k) 
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
/*@ Inv
    (0 <= i) &&
(forall (j:Z), 0 <= j && j < i => a_l[j] == j + 1
          loop assigns i, a_l[0..n-1])
    */
    
            for(i=0;i<n;i++){
            a[i]=i+1;
        }
       
  /*@ Print user assertion at number LoopEntry_1*/ 
/*@ Inv
    (loop assigns i, b_l[0..n-1], count)
    */
    
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
/*@ Inv
    (loop assigns i, b_l[0..n-1], count)
    */
    
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