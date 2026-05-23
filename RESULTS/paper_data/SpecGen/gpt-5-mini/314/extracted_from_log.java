import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class CountRectangles {

    //@ requires radius >= 0;
    //@ ensures \result == (\sum int a; 1 <= a && a <= 2*radius; (\sum int b; 1 <= b && b <= 2*radius; ((a*a + b*b) <= (2*radius)*(2*radius) ? 1 : 0))));
    //@ ensures \result >= 0;
    public static int countRectangles(int radius) {
        int rectangles = 0;
        int diameter = 2 * radius;
        int diameterSquare = diameter * diameter;
        //@ maintaining 1 <= a && a <= 2*radius + 1;
        //@ maintaining rectangles == (\sum int i; 1 <= i && i < a; (\sum int j; 1 <= j && j <= 2*radius; ((i*i + j*j) <= diameterSquare ? 1 : 0)));
        //@ decreases 2*radius + 1 - a;
        for (int a = 1; a <= 2 * radius; a++) {
            //@ maintaining 1 <= b && b <= 2*radius + 1;
            //@ maintaining rectangles == (\sum int i; 1 <= i && i < a; (\sum int j; 1 <= j && j <= 2*radius; ((i*i + j*j) <= diameterSquare ? 1 : 0))) 
            //@          + (\sum int j; 1 <= j && j < b; ((a*a + j*j) <= diameterSquare ? 1 : 0));
            //@ decreases 2*radius + 1 - b;
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