
#include <stdlib.h>

/*@
  logic integer odd_count(int* a, integer lo, integer hi) =
    lo >= hi ? 0
             : odd_count(a, lo, hi - 1) + ((a[hi - 1] % 2 != 0) ? 1 : 0);
*/

/*@
  requires n >= 0;
  requires k >= 0;
  
  ensures \true;
*/
int foo153(int n, int k) {

    int *a = (int *)malloc(sizeof(int) * (n));
    int a_len = n;
    int *b = (int *)malloc(sizeof(int) * (n));
    int b_len = n;
    int i,count=0;
        
    /* >>> LOOP INVARIANT TO FILL <<< */
    /*@
      loop invariant 0 <= i <= n;
      loop invariant \forall integer j; 0 <= j < i ==> a[j] == j + 1;
      loop invariant \forall integer j; 0 <= j < i ==> 1 <= a[j] && a[j] <= n;
      loop invariant (i<n) ==> (0 <= i && i < n);
      loop invariant (!(i<n)) ==> (i == n);
      loop assigns i, a[0..n-1];
    */
    for(i=0;i<n;i++){
        a[i]=i+1;
    }
            
    /* >>> LOOP INVARIANT TO FILL <<< */
    /*@
      loop invariant 0 <= i <= n;
      loop invariant 0 <= count && count <= i;
      loop invariant (i<n) ==> (0 <= i && i < n);
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
            
    /* >>> LOOP INVARIANT TO FILL <<< */
    /*@
      loop invariant 0 <= i <= n;
      loop invariant 0 <= count && count <= i + n;
      loop invariant (i<n) ==> (0 <= i && i < n);
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
