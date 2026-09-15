#include <stdlib.h>

int getNumber(int n, int k);

int getNumber(int n, int k) {

        int *a = (int *)malloc(sizeof(int) * (n));
int a_len = n;
        int *b = (int *)malloc(sizeof(int) * (n));
int b_len = n;
        int i,count=0;
        /*@
        loop invariant 0 <= i <= n;
        loop invariant 0 <= count <= k;
        loop invariant count <= i;
        loop invariant a_len == n;
        loop invariant b_len == n;
        loop invariant \forall integer j; 0 <= j < i ==> a[j] == j + 1;
        loop invariant \forall integer j; 0 <= j < i ==> b[j] == a[j];
        loop invariant \forall integer j; i <= j < n ==> a[j] == 0 || a[j] == j + 1;
        loop invariant i <= n;
        loop invariant count <= k;
        loop invariant count <= i;
        loop invariant b_len == n;
        loop invariant a_len == n;
        loop invariant \forall integer j; 0 <= j < i ==> b[j] == a[j];
        loop invariant \forall integer j; 0 <= j < i ==> a[j] == j + 1;
        loop invariant 0 <= i;
        loop invariant 0 <= count;
        loop assigns i;
        loop assigns count;
        loop assigns b[0..n-1];
        loop assigns a[0..n-1];
        */
        for(i=0;i<n;i++){
            a[i]=i+1;
        }
        /*@
        loop invariant i <= n;
        loop invariant count <= k;
        loop invariant count <= i;
        loop invariant b_len == n;
        loop invariant a_len == n;
        loop invariant \forall integer j; i <= j < n ==> a[j] == 0 || a[j] == j + 1;
        loop invariant \forall integer j; 0 <= j < i ==> b[j] == a[j];
        loop invariant \forall integer j; 0 <= j < i ==> a[j] == j + 1;
        loop invariant 0 <= i;
        loop invariant 0 <= count;
        loop assigns i;
        loop assigns count;
        loop assigns b[0..n-1];
        loop assigns a[0..n-1];
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
        loop invariant i <= n;
        loop invariant count <= k;
        loop invariant count <= i;
        loop invariant b_len == n;
        loop invariant a_len == n;
        loop invariant \forall integer j; i <= j < n ==> b[j] == a[j];
        loop invariant \forall integer j; i <= j < n ==> a[j] == j + 1;
        loop invariant \forall integer j; 0 <= j < i ==> b[j] == a[j];
        loop invariant \forall integer j; 0 <= j < i ==> a[j] >= 1;
        loop invariant \forall integer j; 0 <= j < i ==> a[j] == j + 1;
        loop invariant \forall integer j; 0 <= j < i ==> a[j] != 0;
        loop invariant 0 <= i;
        loop invariant 0 <= count;
        loop assigns i;
        loop assigns count;
        loop assigns b[0..n-1];
        loop assigns a[0..n-1];
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
