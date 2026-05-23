
/*
Analysis:
There is one execution path family determined by the for-loop count and the parity test inside the loop.

Starting state:
average = 0
total = 0

Loop behavior:
- The loop variable index runs from 1 to size inclusive.
- On each iteration:
  - if index is odd, average is increased by index and total is increased by 1.
  - if index is even, neither average nor total changes.

Thus after the loop:
- average is the sum of all odd integers from 1 to size.
- total is the number of odd integers in the range 1..size.
- size itself is unchanged.

Return behavior:
- The function returns average / total.
- For size >= 1, total is at least 1, so the division is well-defined.
- The result is the integer quotient of the sum of odd numbers divided by their count.
*/

int foo358(int size) {

		int average = 0;
		int total = 0;
		
            
        /* >>> LOOP INVARIANT TO FILL <<< */
        
            /*@
          loop invariant 0 <= average;
          loop invariant 0 <= total;
          loop invariant total <= index;
          loop invariant average >= total;
          loop invariant size == \at(size,Pre);
          loop assigns index, average, total;
            */
            for (int index = 1; index <= size; index++) {
			if (index % 2 != 0) {
				average += index;
				total++;
			}
		}
            
		return average / total;
}
