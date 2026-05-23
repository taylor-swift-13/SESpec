#include "../verification_stdlib.h"
    #include "../verification_list.h"
    #include "../int_array_def.h"

    /*@ Extern Coq (Result: Assertion) */
    /*@ Extern Coq (Results: Z -> Assertion) */

/*@ Extern Coq (odd_count : Z -> Z -> Z -> Z) */
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
       
  /*@ Inv
    (0 <= i && i <= n) &&
    (forall (j:Z), 0 <= j && j < i => a[j] == j + 1) &&
    (forall (j:Z), 0 <= j && j < i => 1 <= a[j] && a[j] <= n) &&
    ((i<n) => (0 <= i && i < n)) &&
    ((!(i<n)) => (i == n))
    */
for(i=0;i<n;i++){
            a[i]=i+1;
        }
       
  /*@ Inv
    (0 <= i && i <= n) &&
    (0 <= count && count <= i) &&
    ((i<n) => (0 <= i && i < n))
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
       
  /*@ Inv
    (0 <= i && i <= n) &&
    (0 <= count && count <= i + n) &&
    ((i<n) => (0 <= i && i < n))
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