import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class CountRectangles {

    //@ requires count > 0;
    //@ ensures \result >= 0;
    //@ ensures \result == (\sum int index; 1 <= index && index <= 2 * count; (\sum int i; 1 <= i && i <= 2 * count; (index * index + i * i <= (2 * count) * (2 * count) ? 1 : 0)));
    public static int countRectangles(int count) {
        int result = 0;
        int diameter = 2 * count;
        int center = diameter * diameter;

        //@ maintaining 1 <= index && index <= 2 * count + 1;
        //@ maintaining result >= 0;
        //@ maintaining result == (\sum int idx; 1 - 1 <= idx && idx <= index; (\sum int i; 1 <= i && i <= 2 * count; (idx * idx + i * i < center ? 1 : 0)));  
        //@ decreases (2 * count + 1) - index;
        for (int index = 1; index <= 2 * count; index++) {
            //@ maintaining 1 <= i && i <= 2 * count + 1;
            //@ maintaining result >= 0;
            //@ maintaining result == (\sum int idx; 1 <= idx && idx < index; (\sum int j; 1 <= j && j <= 2 * count; (idx * idx + j * j <= center ? 1 : 0))) + (\sum int j; 1 <= j && j < i; (index * index + j * j <= center ? 1 : 0));
            //@ decreases (2 * count + 1) - i;
            for (int i = 1; i <= 2 * count; i++) {
                int diagnalLengthSquare = (index * index + i * i);
                if (diagnalLengthSquare <= center) {
                    result++;
                }
            }
        }
        return result;
    }
}