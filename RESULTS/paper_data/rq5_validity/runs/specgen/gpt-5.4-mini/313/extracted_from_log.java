import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class CountRectangles {

	//@ requires count >= 0;
	//@ ensures \result >= 0;
	//@ ensures \result == (\sum int index; 1 < index && index <= 2 * count; (\num_of int i; 1 < i && i <= 2 * count; (index * index + i * i) <= (2 * count) * (2 * count)));  
	public static int countRectangles(int count) {
		int ret = 0;
		int diameter = 2 * count;
		int center = diameter * diameter;
		//@ maintaining 0 <= index && index <= 2 * count + 1;
		//@ maintaining ret >= 0;
		//@ maintaining diameter == 2 * count;
		//@ maintaining center == diameter * diameter;
		//@ decreases 2 * count - index + 1;
		for (int index = 1; index <= 2 * count; index++) {
			//@ maintaining 1 <= i && i <= 2 * count + 1;
			//@ maintaining ret >= 0;
			//@ maintaining 0 <= ret && ret <= index * (2 * count);
			//@ decreases 2 * count - i + 1;
			for (int i = 1; i <= 2 * count; i++) {
				int diagnalLengthSquare = (index * index + i * i);
				if (diagnalLengthSquare <= center) {
					ret++;
				}
			}
		}
		return ret;
	}
}