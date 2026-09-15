
#include <stdlib.h>

/*@
  logic integer seq_val(integer idx) = idx + 1;
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
          loop invariant \valid(a + (0..n-1));
          loop invariant \forall integer j; 0 <= j < i ==> a[j] == seq_val(j);
          loop assigns i, a[..];
            */
            for(i=0;i<n;i++){
            a[i]=i+1;
        }
            
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= i <= n;
          loop invariant \valid_read(a + (0..n-1));
          loop invariant \valid(b + (0..n-1));
          loop invariant \forall integer j; 0 <= j < i ==> b[j] == a[j];
          loop invariant 0 <= count <= i;
          loop invariant \forall integer j; 0 <= j < n ==> a[j] == seq_val(j);
          loop assigns i, b[..], count;
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
          loop invariant \valid_read(a + (0..n-1));
          loop invariant \valid(b + (0..n-1));
          loop invariant \forall integer j; 0 <= j < i ==> b[j] == a[j];
          loop invariant 0 <= count;
          loop invariant \forall integer j; 0 <= j < n ==> a[j] == seq_val(j);
          loop assigns i, b[..], count;
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
