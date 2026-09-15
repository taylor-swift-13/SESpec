int getOddOccurrence(int * array, int array_len, int Array);

int getOddOccurrence(int * array, int array_len, int Array) {

		int ret = 0;
		int start = 0;
		/*@
		loop invariant 0 <= index <= Array;
		loop invariant 0 <= start <= index;
		loop invariant start <= index;
		loop invariant start % 2 == \numof{integer k; 0 <= k < index && array[k] % 2 != 0} % 2;
		loop invariant ret == 0 || ret % 2 != 0;
		loop invariant ret == 0 || (\exists integer k; 0 <= k < index && array[k] == ret && array[k] % 2 != 0);
		loop invariant \forall integer k; 0 <= k < index ==> (array[k] % 2 == 0 || array[k] % 2 != 0);
		loop invariant start == index - \numof{integer k; 0 <= k < index && array[k] % 2 == 0};
		loop invariant start == \sum(integer k = 0; k < index; k++) ((array[k] % 2 != 0) ? 1 : 0);
		loop invariant start == \sum(integer k = 0; k < index) (array[k] % 2 != 0 ? 1 : 0);
		loop invariant start == \sum(integer k = 0; k < index) ((array[k] % 2 != 0) ? 1 : 0);
		loop invariant start == \numof{integer k; 0 <= k < index && array[k] % 2 != 0};
		loop invariant start == \numof{integer k | 0 <= k < index && array[k] % 2 != 0};
		loop invariant start == \numof(0, index, \lambda integer k; array[k] % 2 != 0);
		loop invariant start == \numof(0 <= k < index, array[k] % 2 != 0);
		loop invariant start <= index;
		loop invariant start <= index + 1;
		loop invariant start <= Array;
		loop invariant start < Array;
		loop invariant start % 2 == index % 2;
		loop invariant start % 2 == index % 2 || start % 2 != index % 2;
		loop invariant start % 2 == \sum(integer k = 0; k < index) ((array[k] % 2 != 0) ? 1 : 0) % 2;
		loop invariant start % 2 == \numof{integer k; 0 <= k < index && array[k] % 2 != 0} % 2;
		loop invariant start % 2 == 0 || start % 2 == 1;
		loop invariant ret == 0 || ret == array[index-1];
		loop invariant ret == 0 || ret % 2 != 0;
		loop invariant ret == 0 || (ret % 2 != 0);
		loop invariant ret == 0 || (\exists integer k; 0 <= k < index && array[k] == ret);
		loop invariant ret == 0 || (\exists integer k; 0 <= k < index && array[k] == ret && array[k] % 2 != 0);
		loop invariant ret == 0 || (\exists integer k; 0 <= k < index && array[k] % 2 != 0 && ret == array[k]);
		loop invariant index <= Array;
		loop invariant \forall integer k; 0 <= k < index ==> (array[k] % 2 == 0 || array[k] % 2 != 0);
		loop invariant \forall integer k; 0 <= k < index && array[k] % 2 == 0 ==> start >= 0;
		loop invariant \forall integer k; 0 <= k < index && array[k] % 2 != 0 ==> start >= 1;
		loop invariant 0 <= start;
		loop invariant 0 <= index;
		loop invariant (start % 2 != 0) ==> ret == array[index-1];
		loop invariant (\forall integer k; 0 <= k < index ==> array[k] % 2 == 0 || array[k] % 2 != 0);
		loop invariant (\forall integer k; 0 <= k < index && array[k] % 2 == 0 ==> start >= 0);
		loop assigns start;
		loop assigns ret;
		loop assigns index;
		*/
		for (int index = 0; index < Array; index++) {
			if (array[index] % 2 != 0) {
				start++;
				if (start % 2 != 0) {
					ret = array[index];
				}
			}
		}
		return ret;
}
