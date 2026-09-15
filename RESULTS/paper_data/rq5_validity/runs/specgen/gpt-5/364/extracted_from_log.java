import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class OddDays {

    //@ requires n >= 0;
    //@ ensures 0 <= \result && \result < 7;
    //@ ensures \result == (n + n/4 - n/100 + n/400) % 7;
    /*@ spec_public @*/ public static int oddDays(int n) {
        int hund1 = n / 100;
        int hund4 = n / 400;
        int leap = n / 4;
        int ordd = n - leap ;
        if (hund1 != 0) {
            ordd += hund1 ;
            leap -= hund1 ;
        }
        if (hund4 != 0) {
            ordd -= hund4 ;
            leap += hund4 ;
        }
        int days = ordd + leap * 2;
        return days % 7;
    }
}