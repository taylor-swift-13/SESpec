
#include <stdlib.h>

/*@ */

        /*@ */
        

/*@
  requires n >= 0;
  requires k > 0;
  assigns \result;
  ensures (k <= (n + 1) / 2) ==> \result == 2 * k - 1;
  ensures (k > (n + 1) / 2 && k <= n) ==> \result == 2 * (k - (n + 1) / 2);
  ensures (k > n) ==> \result == 0;
  ensures \result >= 0;
  ensures \result == 0 || 1 <= \result <= n;
*/
int foo153(int n, int k) {

        int *a = (int *)malloc(sizeof(int) * (n));
        int a_len = n;
        int *b = (int *)malloc(sizeof(int) * (n));
        int b_len = n;
        int i,count=0;
        
        /*@
          loop invariant 0 <= i <= n;
          loop invariant \forall integer j; 0 <= j < i ==> a[j] == j + 1;
          loop assigns i, a[0..n-1];
        */
        for(i=0;i<n;i++){
            a[i]=i+1;
        }
            
        /*@
          loop invariant 0 <= i <= n;
          loop invariant 0 <= count <= i;
          loop invariant \forall integer j; 0 <= j < i ==> b[j] == a[j];
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
          loop invariant 0 <= i <= n;
          loop invariant 0 <= count <= i + n;
          loop invariant \forall integer j; 0 <= j < i ==> b[j] == a[j];
          loop assigns i, b[0..n-1], count;
        */
        
            
        /*@
          loop invariant 0 <= i <= n;
          loop invariant 0 <= count <= i + n;
          loop invariant \forall integer j; 0 <= j < i ==> b[j] == a[j];
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
