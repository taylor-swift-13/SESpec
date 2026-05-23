import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class GetNumber {

    /*@
      @ requires n >= 0;
      @ ensures (k < 1 || k > n) ==> \result == 0;
      @ ensures (1 <= k && k <= (n+1)/2) ==> \result == 2*k - 1;
      @ ensures ((n+1)/2 < k && k <= n) ==> \result == 2*(k - (n+1)/2);
      @*/
    public static int getNumber(int n, int k) {
        int a[]=new int[n];
        int b[]=new int[n];
        int i,count=0;
        /*@ 
          @ maintaining 0 <= i && i <= n;
          @ maintaining (\forall int t; 0 <= t && t < i; a[t] == t + 1);
          @ decreases n - i;
          @*/
        for(i=0;i<n;i++){
            a[i]=i+1;
        }
        /*@
          @ maintaining 0 <= i && i <= n;
          @ maintaining (\forall int t; 0 <= t && t < i; b[t] == a[t]);
          @ maintaining (\forall int t; 0 <= t && t < n; a[t] == t + 1);
          @ maintaining 0 <= count && count <= i;
          @ maintaining count == (\sum int t; 0 <= t && t < i; (a[t] % 2 != 0 ? 1 : 0));
          @ decreases n - i;
          @*/
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
          @ maintaining 0 <= i && i <= n;
          @ maintaining (\forall int t; 0 <= t && t < i; b[t] == a[t]);
          @ maintaining (\forall int t; 0 <= t && t < n; a[t] == t + 1);
          @ maintaining 0 <= count && count <= n;
          @ maintaining count == (\sum int t; 0 <= t && t < n; (a[t] % 2 != 0 ? 1 : 0))
          @                       + (\sum int t; 0 <= t && t < i; (a[t] % 2 == 0 ? 1 : 0));
          @ decreases n - i;
          @*/
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
}