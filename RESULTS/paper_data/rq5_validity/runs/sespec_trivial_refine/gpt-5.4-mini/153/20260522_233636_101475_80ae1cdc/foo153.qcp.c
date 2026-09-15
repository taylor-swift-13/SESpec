#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */
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
       
  /*0*/ 
 /*@ Inv
    (0 <= i && i <= n) &&
    (forall (j:Z), 0 <= j && j < i => a[j] == j + 1)
    */
for(i=0;i<n;i++){
            a[i]=i+1;
        }
       
  /*1*/ 
 /*@ Inv
    (0 <= i && i <= n) &&
    (0 <= count && count <= i) &&
    (forall (j:Z), 0 <= j && j < i => b[j] == a[j])
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
       
  /*2*/ 
 /*@ Inv
    (0 <= i && i <= n) &&
    (0 <= count && count <= i + n) &&
    (forall (j:Z), 0 <= j && j < i => b[j] == a[j])
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