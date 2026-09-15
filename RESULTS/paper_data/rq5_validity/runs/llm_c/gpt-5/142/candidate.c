int isEven(int x);
int isOdd(int x);

/*@ 
  requires \true;
  assigns \nothing;
  ensures \result == 0 || \result == 1;
  ensures (\result == 1) <==> (x % 2 == 0);
  behavior even:
    assumes x % 2 == 0;
    ensures \result == 1;
  behavior odd:
    assumes x % 2 != 0;
    ensures \result == 0;
  complete behaviors even, odd;
  disjoint behaviors even, odd;
*/
int isEven(int x) {

         	return x%2 == 0;
}

/*@
  requires \true;
  assigns \nothing;
  ensures \result == 0 || \result == 1;
  ensures (\result == 1) <==> (x % 2 != 0);
  behavior odd:
    assumes x % 2 != 0;
    ensures \result == 1;
  behavior even:
    assumes x % 2 == 0;
    ensures \result == 0;
  complete behaviors odd, even;
  disjoint behaviors odd, even;
*/
int isOdd(int x) {

         	return x%2 != 0;
}
