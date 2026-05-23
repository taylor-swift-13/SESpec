import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class GetNumber {

    //@ requires n >= 0;
    //@ // If k is within the number of odds
    //@ ensures (1 <= k && k <= (n + 1) / 2) ==> \result == 2 * k - 1;
    //@ // If k is within the remaining evens
    //@ ensures ((n + 1) / 2 < k && k <= n) ==> \result == 2 * (k - (n + 1) / 2);
    //@ // Otherwise no such k-th element in the ordering (odds first, then evens)
    //@ ensures (k < 1 || k > n) ==> \result == 0;
    public static int getNumber(int n, int k) {
        int a[]=new int[n];
        int b[]=new int[n];
        int i,count=0;
        //@ // Loop 1: initialize a[]
        //@ loop_invariant 0 <= i && i <= n;
        //@ loop_invariant (\forall int j; 0 <= j && j < i; a[j] == j + 1);
        //@ decreases n - i;
        for(i=0;i<n;i++){
            a[i]=i+1;
        }
        //@ // Loop 2: copy and count odds
        //@ loop_invariant 0 <= i && i <= n;
        //@ loop_invariant (\forall int j; 0 <= j && j < i; b[j] == a[j]);
 
        //@ decreases n - i;
        for(i=0;i<n;i++){
            b[i]=a[i];
            if(a[i]%2!=0){
                count++;
                if(count==k){
                    return a[i];
                }
            }
        }
        //@ // At this point count == number of odds in 1..n
        //@ ghost int numOdds = (\sum int j; 0 <= j && j < n; (a[j] % 2 != 0 ? 1 : 0));
        //@ assert count == numOdds;
        //@ // Loop 3: copy and count evens (count continues from numOdds)
        //@ loop_invariant 0 <= i && i <= n;
        //@ loop_invariant (\forall int j; 0 <= j && j < i; b[j] == a[j]);
        //@ loop_invariant count == numOdds + (\sum int j; 0 <= j && j < i; (a[j] % 2 == 0 ? 1 : 0));
        //@ decreases n - i;
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