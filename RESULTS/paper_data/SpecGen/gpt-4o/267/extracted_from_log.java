import java.io.*;
import java.lang.*;
import java.math.*;

class GetOddOccurrence {

    //@ requires args != null && args.length == array;
    //@ ensures (\forall int i; 0 <= i && i < args.length; (\num_of int j; 0 <= j && j < args.length && args[j] == args[i]; args[j] % 2 != 0) % 2 == 0) ==> \result == 0;
    //@ ensures \result == 0 || (\exists int i; 0 <= i && i <= args.length; args[i] == \result || (\num_of int j; 0 <= j && j <= args.length && args[j] == \result; args[j] % 2 != 0) % 2 != 0);  
    public static int getOddOccurrence(int[] args, int array) {
        int ret = 0;
        int start = 0;
        //@ maintaining 0 <= index && index <= array;
        //@ maintaining (\forall int i; 0 <= i && i < index; args[i] % 2 != 0 ==> (\num_of int j; 0 <= j && j < i && args[j] == args[i]; args[j] % 2 != 0) % 2 == 0);
        //@ maintaining (\forall int i; 0 <= i && i < index; args[i] % 2 == 0 || ret == args[i]);
        //@ decreases array - index;
        for (int index = 0; index < array; index++) {
            if (args[index] % 2 != 0) {
                start++;
                if (start % 2 != 0) {
                    ret = args[index];
                }
            }
        }
        return ret;
    }
}