#include <stdlib.h>

int getNumber(int n, int k);

int getNumber(int n, int k) {

        int *a = (int *)malloc(sizeof(int) * (n));
int a_len = n;
        int *b = (int *)malloc(sizeof(int) * (n));
int b_len = n;
        int i,count=0;
        /*@
        loop invariant i <= n;
        loop invariant count <= n;
        loop invariant count <= k;
        loop invariant count <= i;
        loop invariant \forall integer j; 0 <= j < i ==> b[j] == a[j];
        loop invariant \forall integer j; 0 <= j < i ==> a[j] == j + 1;
        loop invariant \forall integer j; 0 <= j < i ==> 1 <= a[j] <= n;
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
        loop invariant 0 <= i <= n;
        loop invariant 0 <= count <= k;
        loop invariant count <= i;
        loop invariant \forall integer j; 0 <= j < i ==> a[j] == j + 1;
        loop invariant \forall integer j; 0 <= j < i ==> 1 <= a[j] <= n;
        loop invariant \forall integer j; 0 <= j < i ==> b[j] == a[j];
        loop assigns i;
        loop assigns count;
        loop assigns a[0..n-1];
        loop assigns b[0..n-1];
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
