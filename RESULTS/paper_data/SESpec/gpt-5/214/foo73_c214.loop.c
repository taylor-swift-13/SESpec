
/*@
logic integer cat(integer n) =
  n == 0 ? 1 :
  \sum(integer t = 0, n-1) (cat(t) * cat(n - 1 - t));
*/

/*@
logic integer partial_cat_sum(int* a, integer i, integer j) =
  j <= 0 ? 0 :
  partial_cat_sum(a, i, j - 1) + a[j - 1] * a[i - j];
*/


/*@
logic integer cat(integer n) =
  n == 0 ? 1 :
  \sum(integer t = 0, n-1) (cat(t) * cat(n - 1 - t));
*/

/*@
logic integer partial_cat_sum(int* a, integer i, integer j) =
  j <= 0 ? 0 :
  partial_cat_sum(a, i, j - 1) + a[j - 1] * a[i - j];
*/


int foo73_c214(int num) {

        int *catalan = (int *)malloc(sizeof(int) * (num + 1));
int catalan_len = num + 1;
        catalan[0] = 1;
        
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 1 <= i <= num + 1;
          loop invariant \forall integer t; 0 <= t < i ==> catalan[t] == cat(t);
          loop assigns i, catalan[..], j;
            */
            for (int i = 1; i <= num; i++) {
            catalan[i] = 0;
            
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= j <= i;
          loop invariant catalan[i] == partial_cat_sum(catalan, i, j);
          loop assigns catalan[i], j;
            */
            for (int j = 0; j < i; j++) {
                catalan[i] += catalan[j] * catalan[i - j - 1];
            }
            
        }
            
        return catalan[num];
}
