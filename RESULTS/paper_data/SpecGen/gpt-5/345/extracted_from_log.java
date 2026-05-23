import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class Sumoffactors {

    //@ ensures \result == (\sum int k; 2 <= k && k <= n && n % k == 0 && k % 2 == 0; k);
    /*@ spec_public @*/ public static int sumoffactors(int n) {
        int sum=0;
        //@ maintaining 2 <= i && i <= n + 1;
        //@ maintaining sum == (\sum int k; 2 <= k && k < i && n % k == 0 && k % 2 == 0; k);
        //@ maintaining sum >= 0;
        //@ decreases n - i + 1;
        for(int i=2;i<=n;i++)
        {
            if(n%i==0)
            {
                if(i%2==0)
                    sum+=i;
            }
        }
        return sum;
    }
}