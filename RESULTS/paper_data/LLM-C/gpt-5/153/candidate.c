#include <stdlib.h>

/*@ 
  logic integer odd_total(integer n) = (n + 1) / 2;

  logic integer kth_value(integer n, integer k) =
    (n <= 0 || k <= 0 || k > n) ? 0 :
    (k <= odd_total(n) ? 2*k - 1 : 2*(k - odd_total(n)));
*/

/*@ 
  requires n >= 0;

  behavior invalid_k:
    assumes k <= 0 || k > n;
    ensures \result == 0;

  behavior odd_part:
    assumes 1 <= k && k <= odd_total(n);
    ensures \result == 2*k - 1;

  behavior even_part:
    assumes odd_total(n) < k && k <= n;
    ensures \result == 2*(k - odd_total(n));

  complete behaviors invalid_k, odd_part, even_part;
  disjoint behaviors invalid_k, odd_part, even_part;

  ensures \result == kth_value(n,k);
  ensures 0 <= \result <= n;
*/
int getNumber(int n, int k);

int getNumber(int n, int k) {

/*@ ghost; */
        int *a = (int *)malloc(sizeof(int) * (n));
int a_len = n;
        int *b = (int *)malloc(sizeof(int) * (n));
int b_len = n;
        int i,count=0;
/*@ 
  loop invariant 0 <= i <= n;
  loop assigns i, a[0..n-1];
  loop variant n - i;
*/
        for(i=0;i<n;i++){
            a[i]=i+1;
        }
//@ assert \forall integer j; 0 <= j < n ==> a[j] == j+1;
/*@ 
  loop invariant 0 <= i <= n;
  loop invariant 0 <= count <= i;
  loop assigns i, count, b[0..n-1];
  loop variant n - i;
*/
        for(i=0;i<n;i++){
            b[i]=a[i];
            if(a[i]%2!=0){
                count++;
                if(count==k){
                    //@ assert 1 <= k && k <= odd_total(n);
                    //@ assert a[i] == 2*k - 1;
                    return a[i];
                }
            }
        }
/*@ 
  loop invariant 0 <= i <= n;
  loop invariant 0 <= count <= n;
  loop assigns i, count, b[0..n-1];
  loop variant n - i;
*/
        for(i=0;i<n;i++){
            b[i]=a[i];
            if(a[i]%2==0){
                count++;
                if(count==k){
                    //@ assert odd_total(n) < k && k <= n;
                    //@ assert a[i] == 2*(k - odd_total(n));
                    return a[i];
                }
            }
        }
        return 0;
}
