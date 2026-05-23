import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class CountRectangles {

    //@ requires count >= 0 && count <= 16383;
    //@ ensures 0 <= \result && \result <= (2*count) * (2*count);
    //@ ensures count == 0 ==> \result == 0;
	public static int countRectangles(int count) {
		int ret = 0;
		int diameter = 2 * count;
		int center = diameter * diameter;
        //@ maintaining 1 <= i && i <= 2*count + 1;
        //@ maintaining 0 <= ret && ret <= (i - 1) * (2*count);
        //@ maintaining diameter == 2*count && center == diameter * diameter;
        //@ decreases (2*count + 1 - i);
		for (int i = 1; i <= 2 * count; i++) {
            //@ maintaining 1 <= c && c <= 2*count + 1;
            //@ maintaining 0 <= ret && ret <= (i - 1) * (2*count) + (c - 1);
            //@ maintaining diameter == 2*count && center == diameter * diameter;
            //@ decreases (2*count + 1 - c);
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