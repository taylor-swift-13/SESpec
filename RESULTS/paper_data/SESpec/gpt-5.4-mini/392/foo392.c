
/*@ logic integer fact(integer n) = n <= 0 ? 1 : n * fact(n - 1); */

/*@ 
  assigns \nothing;
  ensures num <= 0 ==> \result == 1;
  ensures \result >= 0;
  ensures \result < 100;
  ensures num > 0 ==> (\result == 0 <==> fact(num) % 100 == 0);
*/
int foo392(int num) {
	int ret = 1;

	/*@
	  loop invariant number >= 1;
	  loop invariant num == \at(num,Pre);
	  loop invariant ret == fact(number - 1);
	  loop invariant ret >= 1;
	  loop invariant ret == fact(number - 1) && (number - 1) >= 0;
	  loop invariant \forall integer k; 1 <= k < number ==> fact(k) > 0;
	  loop invariant (number > num) ==> ret == fact(num);
	  loop invariant (number <= \at(num,Pre)) ==> (ret == fact(number - 1));
	  loop invariant (!(number <= \at(num,Pre))) ==> (num == \at(num,Pre));
	  loop assigns number, ret;
	*/
	for (int number = 1; number <= num; number++) {
		ret *= number;
	}

	int result = (int) (ret % 100);
	return result;
}
