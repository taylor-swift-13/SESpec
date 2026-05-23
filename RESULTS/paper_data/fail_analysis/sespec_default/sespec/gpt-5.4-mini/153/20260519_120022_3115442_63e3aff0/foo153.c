
/*@
  logic integer count_occ(int* a, integer lo, integer hi, integer v) =
    lo >= hi ? 0
              : count_occ(a, lo, hi - 1, v) + (a[hi - 1] == v ? 1 : 0);
*/

int foo153(int n, int k) {

        int *a = (int *)malloc(sizeof(int) * (n));
        int a_len = n;
        int *b = (int *)malloc(sizeof(int) * (n));
        int b_len = n;
        int i,count=0;

        /* >>> LOOP INVARIANT TO FILL <<< */

            /*@
          loop invariant \forall integer j; 0 <= j < i ==> a[j] == j + 1;
          loop assigns i, a[0..n-1];
            */
            for(i=0;i<n;i++){
            a[i]=i+1;
        }

        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
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
