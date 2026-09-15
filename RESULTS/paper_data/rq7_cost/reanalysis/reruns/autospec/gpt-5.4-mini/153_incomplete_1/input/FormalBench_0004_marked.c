#include <stdlib.h>

int getNumber(int n, int k);

/* 4. FUNC CONTRACT */
int getNumber(int n, int k) {

        int *a = (int *)malloc(sizeof(int) * (n));
int a_len = n;
        int *b = (int *)malloc(sizeof(int) * (n));
int b_len = n;
        int i,count=0;
        /* 1. LOOP INVARIANT */
        for(i=0;i<n;i++){
            a[i]=i+1;
        }
        /* 2. LOOP INVARIANT */
        for(i=0;i<n;i++){
            b[i]=a[i];
            if(a[i]%2!=0){
                count++;
                if(count==k){
                    return a[i];
                }
            }
        }
        /* 3. LOOP INVARIANT */
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
