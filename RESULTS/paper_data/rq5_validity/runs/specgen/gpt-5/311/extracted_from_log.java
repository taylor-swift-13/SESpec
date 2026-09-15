import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class CountRectangles {

	/*@ spec_public @*/
	//@ requires count >= 0;
	//@ ensures 0 <= \result && \result <= (2*count)*(2*count);
	//@ ensures count == 0 ==> \result == 0;
	//@ ensures count > 0 ==> \result > 0;
	public static int countRectangles(int count) {
		int result = 0;
		int diameter = 2 * count;
		int center = diameter * diameter;
		//@ maintaining 1 <= index && index <= 2*count + 1;
		//@ maintaining 0 <= result && result <= (index - 1) * (2*count);
		//@ maintaining diameter == 2*count && center == diameter*diameter;
		//@ decreases (2*count + 1) - index;
		for (int index = 1; index <= 2 * count; index++) {
			//@ maintaining 1 <= i && i <= 2*count + 1;
			//@ maintaining 0 <= result && result <= (index - 1) * (2*count) + (i - 1);
			//@ maintaining diameter == 2*count && center == diameter*diameter;
			//@ decreases (2*count + 1) - i;
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