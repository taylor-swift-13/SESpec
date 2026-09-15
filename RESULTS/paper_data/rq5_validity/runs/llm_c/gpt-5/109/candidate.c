/*@
  requires \true;
  assigns \nothing;
  ensures \result == ((n % 3 == 0) ? 3 : 0) + ((n % 5 == 0) ? 5 : 0);
  ensures \result == 0 || \result == 3 || \result == 5 || \result == 8;
  ensures 0 <= \result <= 8;
  terminates \true;

  behavior none_divisible:
    assumes n % 3 != 0 && n % 5 != 0;
    ensures \result == 0;

  behavior only_three:
    assumes n % 3 == 0 && n % 5 != 0;
    ensures \result == 3;

  behavior only_five:
    assumes n % 3 != 0 && n % 5 == 0;
    ensures \result == 5;

  behavior both:
    assumes n % 3 == 0 && n % 5 == 0;
    ensures \result == 8;

  complete behaviors none_divisible, only_three, only_five, both;
  disjoint behaviors none_divisible, only_three, only_five, both;
*/
int fizzBuzz(int n);

int fizzBuzz(int n) {

        int res = 0;
        res += ((n % 3 == 0) ? 3 : 0);
        res += ((n % 5 == 0) ? 5 : 0);
        return res;
}
