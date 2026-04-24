#include <stdlib.h>

int getNumber(int n, int k);

int getNumber(int n, int k) {

        int *a = (int *)malloc(sizeof(int) * (n));
int a_len = n;
        int *b = (int *)malloc(sizeof(int) * (n));
int b_len = n;
        int i,count=0;
        for(i=0;i<n;i++){
            a[i]=i+1;
        }
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
