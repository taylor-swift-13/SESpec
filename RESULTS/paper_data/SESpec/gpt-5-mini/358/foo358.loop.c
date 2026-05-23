
int foo358(int size) {

	int average = 0;
	int total = 0;
	
	/*@
	  loop invariant index >= 1;
	  loop invariant 0 <= total <= index - 1;
	  loop invariant 0 <= average;
	  loop invariant (\at(size,Pre) >= 0) ==> (total <= \at(size,Pre));
	  loop invariant total > 0 ==> (\exists integer k; 1 <= k < index && k % 2 != 0);
	  loop invariant size == \at(size,Pre);
	  loop invariant (\at(size,Pre) < 1) ==> (average == 0 && total == 0);
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
