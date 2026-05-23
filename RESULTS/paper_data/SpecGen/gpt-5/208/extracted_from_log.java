import java.io.*;
import java.lang.*;
import java.math.*;

class FindElement {

    /*@ spec_public @*/
    //@ requires arr != null && ranges != null;
    //@ requires 0 <= num && num <= ranges.length;
    //@ requires 0 <= count && count < arr.length;
    //@ requires (\forall int r; 0 <= r && r < num; ranges[r] != null && ranges[r].length >= 2);
    //@ requires (\forall int r; 0 <= r && r < num;
    //@             0 <= ranges[r][0] && ranges[r][0] <= ranges[r][1] && ranges[r][1] < arr.length);
    //@ ensures 0 <= count && count < arr.length;
    //@ ensures (\forall int i; 0 <= i && i < arr.length; arr[i] == \old(arr[i]));
    //@ ensures (\forall int r; 0 <= r && r < ranges.length && ranges[r] != null && ranges[r].length >= 2;
    //@             (\forall int c; 0 <= c && c < ranges[r].length; ranges[r][c] == \old(ranges[r][c])));
    //@ ensures \result == arr[count];
	public static int findElement(int[] arr, int[][] ranges, int num, int count) {
        //@ maintaining 0 <= num && num <= ranges.length;
        //@ maintaining 0 <= count && count < arr.length;
        //@ maintaining (\forall int r0; 0 <= r0 && r0 < num; ranges[r0] != null && ranges[r0].length >= 2);
        //@ maintaining (\forall int r0; 0 <= r0 && r0 < num;
        //@                0 <= ranges[r0][0] && ranges[r0][0] <= ranges[r0][1] && ranges[r0][1] < arr.length);
        //@ maintaining 0 <= r && r < num;
        //@ decreases r;
		for (int r = num - 1; r >= 0; r--) {
			int j = ranges[r][0];
			int top = ranges[r][1];
			if (j <= count && top >= count) {
				if (count == j) {
					count = top;
				} else {
					count = count - 1;
				}
			}
		}
		return arr[count];
	}
}