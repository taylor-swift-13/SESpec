import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class CountRectangles {

	//@ requires count >= 0;
	//@ ensures \result >= 0;
	public static int countRectangles(int count) {
		int result = 0;
		int diameter = 2 * count;
		int center = diameter * diameter;
		//@ maintaining 0 <= index && index <= 2 * count + 1;
		//@ maintaining result >= 0;
		//@ decreases 2 * count - index + 1;
		for (int index = 1; index <= 2 * count; index++) {
			//@ maintaining 0 <= i && i <= 2 * count + 1;
			//@ maintaining result >= 0;
			//@ decreases 2 * count - i + 1;
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