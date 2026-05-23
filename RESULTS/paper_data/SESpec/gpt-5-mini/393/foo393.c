
/*@ logic integer fact(integer n) =
      n <= 0 ? 1 : n * fact(n - 1);
*/

/*@
  requires \true;
  assigns \nothing;
  ensures num >= 1 ==> \result == (int)(fact(num) % 100);
*/
int foo393(int num) {

		int ret = 1;

            /*@
              loop invariant loop >= 1;
              loop invariant (loop <= num + 1) || (num < 1);
              loop invariant ret == fact(loop - 1);
              loop assigns ret, loop;
              loop variant num - loop + 1;
            */
            for (int loop = 1; loop <= num; loop++) {
			ret *= loop;
		}

		int remainder = (int) (ret % 100);
		return remainder;
}
