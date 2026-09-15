import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;

class CountRectangles {

	/*@ 
	  @ requires count >= 0;
	  @ ensures \result >= 0 && \result <= (2*count)*(2*count);
	  @ ensures \result == (\sum int idx; 1 <= idx && idx <= 2*count;
	  @                         (\sum int j; 1 <= j && j <= 2*count;
	  @                              ((idx*idx + j*j <= (2*count)*(2*count)) ? 1 : 0)
	  @                         )
	  @                       );
	  @*/
	public static int countRectangles(int count) {
		int result = 0;
		int diameter = 2 * count;
		int center = diameter * diameter;
 
 
 
 
		//@                         (\sum int j; 1 <= j && j <= 2*count;
		//@                              ((idx*idx + j*j <= center) ? 1 : 0)
		//@                         )
		//@                       );
		//@ decreases 2*count - (1) + 1;
		for (int index = 1; index <= 2 * count; index++) {
			//@ maintaining 1 <= i && i <= 2*count + 1;
			//@ maintaining result == (\sum int idx; 1 <= idx && idx < index;
			//@                         (\sum int j; 1 <= j && j <= 2*count;
			//@                              ((idx*idx + j*j <= center) ? 1 : 0)
			//@                         )
			//@                       ) + (\sum int j; 1 <= j && j < i;
			//@                              ((index*index + j*j <= center) ? 1 : 0)
			//@                         );
			//@ decreases 2*count - (1) + 1;
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