import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class CountRectangles {

	//@ requires count >= 0;
	//@ ensures 0 <= \result && \result <= (2*count)*(2*count);
	//@ ensures \result == (\num_of int ii,jj; 1 <= ii && ii <= 2*count && 1 <= jj && jj <= 2*count; ii*ii + jj*jj <= (2*count)*(2*count));
	public static int countRectangles(int count) {
		int ret = 0;
		int diameter = 2 * count;
		int center = diameter * diameter;
		/*@ 
		  @ maintaining 1 <= index && index <= 2*count + 1;
		  @ maintaining ret == (\num_of int ii,jj; 1 - 1 <= ii && ii < index && 1 <= jj && jj <= 2*count; ii*ii + jj*jj <= center);  
		  @ decreases (2*count + 1) - index;
		  @*/
		for (int index = 1; index <= 2 * count; index++) {
			/*@
			  @ maintaining 1 <= i && i <= 2*count + 1;
			  @ maintaining ret == (\num_of int ii,jj; 1 <= ii && ii < index && 1 <= jj && jj <= 2*count; ii*ii + jj*jj <= center)
			  @                   + (\num_of int jj; 1 <= jj && jj < i; index*index + jj*jj <= center);
			  @ decreases (2*count + 1) - i;
			  @*/
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