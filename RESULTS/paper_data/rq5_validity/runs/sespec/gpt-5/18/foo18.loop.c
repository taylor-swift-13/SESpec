
/*@
  requires \valid(&a[0] + (0..a_len-1));
  requires \forall integer i; 0 <= i < a_len ==> 0 <= a[i] <= 100;
*/

void foo18(int * a, int a_len) {

    int N = a_len;
    
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant N == \at(a_len,Pre);
          loop invariant a_len == \at(a_len,Pre);
          loop invariant a == \at(a,Pre);
          loop assigns a[0..N-1];
            */
            for (int i = 1; i < N; i++) { // N branches
      int j = i - 1;
      int x = a[i];

      
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= j + 1 <= i;
          loop assigns a[0..N-1], j;
            */
            while ((j >= 0) && (a[j] > x)) {
        a[j + 1] = a[j];
        j--;
      }
            
      a[j + 1] = x;
    }
            
}
