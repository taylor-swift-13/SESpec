
#include <stdlib.h>

/*@
  assigns \nothing;
  ensures
    ( \exists integer i;
        0 <= i < n &&
        (\numof integer t; 0 <= t <= i && (seq_val(t) % 2 != 0)) == k &&
        \result == seq_val(i)
      )
    ||
    ( \exists integer i2;
        0 <= i2 < n &&
        (\numof integer t2; 0 <= t2 <= i2 && (seq_val(t2) % 2 == 0)) == k &&
        (\forall integer u; 0 <= u < n ==> (\numof integer t3; 0 <= t3 <= u && (seq_val(t3) % 2 != 0)) < k) &&
        \result == seq_val(i2)
      )
    ||
    ( \result == 0 &&
      (\forall integer u1; 0 <= u1 < n ==> (\numof integer t4; 0 <= t4 <= u1 && (seq_val(t4) % 2 != 0)) < k) &&
      (\forall integer u2; 0 <= u2 < n ==> (\numof integer t5; 0 <= t5 <= u2 && (seq_val(t5) % 2 == 0)) < k)
    );
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
