
void foo63() {

    int i;
    int j;
    int a;
    int b;

    a = 0;
    b = 0;
    j = 1;
    i = 0;

    
            
        /*@
          loop invariant 0 <= a;
          loop invariant 0 <= b;
          loop invariant 0 <= i;
          loop invariant 1 <= j;

          loop invariant i == 2 * a;
          loop invariant j == i + 1;
          loop invariant b == a;

          loop invariant i % 2 == 0;
          loop invariant j % 2 == 1;
          loop invariant a == b;
          loop invariant a <= i;
          loop invariant b <= i;
          loop invariant j > i;

          loop invariant \exists integer k; 0 <= k <= a && i == 2 * k;
          loop invariant \exists integer k; 0 <= k <= a && j == 2 * k + 1;
          loop invariant \exists integer k; 0 <= k <= a && b == k;

          loop assigns a, b, i, j;
            */
            while (unknown()) {
       a = a + 1;
       b = b + j - i;
       i = i + 2;
       if (i % 2 == 0){
       j = j + 2;
      }
       else{
       j = j + 1;
      }
      }
            

  }
