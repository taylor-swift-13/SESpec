import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class Sumoffactors {

    /*@ 
      @ requires n >= 0;
 
 
      @*/
    public static int sumoffactors(int n) {
        int sum=0;
        /*@ 
          @ maintaining 2 <= i && i - 1 <= n + 1;  
 
          @ decreases n - i + 1;
          @*/
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
