#include <stdlib.h>

/*@
    requires n >= 0;
    requires k >= 0;
    assigns \result;
    behavior within_range:
      assumes 1 <= k && k <= n;
      ensures (k <= (n + 1) / 2) ==> \result == 2 * k - 1;
      ensures (k >  (n + 1) / 2) ==> \result == 2 * (k - (n + 1) / 2);
    behavior out_of_range:
      assumes !(1 <= k && k <= n);
      ensures \result == 0;
    complete behaviors within_range, out_of_range;
    disjoint behaviors within_range, out_of_range;
*/
int getNumber(int n, int k) {

        int *a = (int *)malloc(sizeof(int) * (n));
int a_len = n;
        int *b = (int *)malloc(sizeof(int) * (n));
int b_len = n;
        int i,count=0;
        /*@
            loop invariant 0 <= i <= n;
            loop invariant \forall integer j; 0 <= j < i ==> a[j] == j + 1;
            loop assigns i, a[0..n-1];
            loop variant n - i;
        */
        for(i=0;i<n;i++){
            a[i]=i+1;
        }
        /*@
            loop invariant 0 <= i <= n;
            loop invariant 0 <= count <= i;
            loop invariant \forall integer j; 0 <= j < i ==> b[j] == a[j];
            loop assigns i, b[0..n-1], count;
            loop variant n - i;
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
            loop invariant 0 <= count <= n;
            loop invariant \forall integer j; 0 <= j < i ==> b[j] == a[j];
            loop assigns i, b[0..n-1], count;
            loop variant n - i;
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
