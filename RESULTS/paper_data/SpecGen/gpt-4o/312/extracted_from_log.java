import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class CountRectangles {

    //@ requires count > 0;
    //@ ensures \result >= 0;
    //@ ensures \result == (\sum int i; 1 <= i && i <= 2 * count; (\sum int c; 1 <= c && c <= 2 * count; ((i * i + c * c) <= (2 * count) * (2 * count) ? 1 : 0)));
    public static int countRectangles(int count) {
        int ret = 0;
        int diameter = 2 * count;
        int center = diameter * diameter;
        //@ maintaining 1 <= i && i <= 2 * count + 1;
        //@ maintaining ret >= 0;
        //@ maintaining ret == (\sum int i1; 1 - 1 <= i1 && i1 <= i; (\sum int c1; 1 < c1 && c1 - 1 <= 2 * count; ((i1 * i1 + c1 * c1) <= center ? 1 : 0)));  
        //@ decreases (2 * count + 1) - i;
        for (int i = 1; i <= 2 * count; i++) {
            //@ maintaining 1 <= c && c <= 2 * count + 1;
            //@ maintaining ret >= 0;
            //@ maintaining ret == (\sum int i1; 1 <= i1 && i1 < i; (\sum int c1; 1 <= c1 && c1 <= 2 * count; ((i1 * i1 + c1 * c1) <= center ? 1 : 0))) + (\sum int c2; 1 <= c2 && c2 < c; ((i * i + c2 * c2) <= center ? 1 : 0));
            //@ decreases (2 * count + 1) - c;
            for (int c = 1; c <= 2 * count; c++) {
                int diagnalLengthSquare = (i * i + c * c);
                if (diagnalLengthSquare <= center) {
                    ret++;
                }
            }
        }
        return ret;
    }
}