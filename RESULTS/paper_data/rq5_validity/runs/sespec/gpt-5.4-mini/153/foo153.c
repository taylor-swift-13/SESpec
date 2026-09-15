
#include <stdlib.h>

/*@
  requires n >= 0;
  requires k > 0;

  ensures \true;
  ensures \true;
  ensures \true;
  ensures (n <= 0) ==> \result == 0;
  ensures (k <= 0) ==> \result == 0;
*/
int foo153(int n, int k) {

        int *a = (int *)malloc(sizeof(int) * (n));
        int a_len = n;
        int *b = (int *)malloc(sizeof(int) * (n));
        int b_len = n;
        int i,count=0;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= i;
          loop invariant \forall integer j; 0 <= j < i ==> a[j] == j + 1;
          loop invariant \forall integer j; 0 <= j < i ==> a[j] > 0;
          loop invariant \forall integer j; 0 <= j < i ==> a[j] <= n;
          loop invariant (i == 0) || a[i-1] == i;
          loop invariant (i < n) ==> (i >= 0);
          loop invariant \forall integer j; i <= j < n ==> \true;
          loop assigns i, a[0..n-1];
            */
            for(i=0;i<n;i++){
            a[i]=i+1;
        }
            
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= i;
          loop invariant 0 <= count <= i;
          loop invariant (i < n) ==> (i >= 0);
          loop invariant \forall integer j; i <= j < n ==> \true;
          loop assigns i, b[0..n-1], count;
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
            
        /*@
          loop invariant 0 <= i;
          loop invariant (i < n) ==> (i >= 0);
          loop invariant \forall integer j; i <= j < n ==> \true;
          loop assigns i, b[0..n-1], count;
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
