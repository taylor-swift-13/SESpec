import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class CountRectangles {

    //@ requires radius >= 0;
    //@ ensures \result == (\sum int a; 1 <= a && a <= 2*radius; (\sum int b; 1 <= b && b <= 2*radius; (((a*a + b*b) <= ((2*radius)*(2*radius))) ? 1 : 0)));
    //@ ensures 0 <= \result && \result <= (2*radius)*(2*radius);
    public static int countRectangles(int radius) {
        int rectangles = 0;
        int diameter = 2 * radius;
        int diameterSquare = diameter * diameter;
        //@ maintaining 1 <= a && a <= 2*radius + 1;
        //@ maintaining diameter == 2*radius && diameterSquare == diameter*diameter;
        //@ maintaining rectangles == (\sum int aa; 1 <= aa && aa < a; (\sum int bb; 1 <= bb && bb <= 2*radius; (((aa*aa + bb*bb) <= diameterSquare) ? 1 : 0)));
        //@ decreases (2*radius + 1 - a);
        for (int a = 1; a <= 2 * radius; a++) {
            //@ maintaining 1 <= b && b <= 2*radius + 1;
            //@ maintaining diameter == 2*radius && diameterSquare == diameter*diameter;
            //@ maintaining rectangles == (\sum int aa; 1 <= aa && aa < a; (\sum int bb; 1 <= bb && bb <= 2*radius; (((aa*aa + bb*bb) <= diameterSquare) ? 1 : 0))) + (\sum int bb; 1 <= bb && bb < b; (((a*a + bb*bb) <= diameterSquare) ? 1 : 0));
            //@ decreases (2*radius + 1 - b);
            for (int b = 1; b <= 2 * radius; b++) {
                int diagnalLengthSquare = (a * a + b * b);
                if (diagnalLengthSquare <= diameterSquare) {
                    rectangles++;
                }
            }
        }
        return rectangles;
    }
}