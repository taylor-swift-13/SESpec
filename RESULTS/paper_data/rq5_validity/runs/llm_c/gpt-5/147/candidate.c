/*@ 
  inductive pow3(integer n) {
    case pow3_one: pow3(1);
    case pow3_mul3: \forall integer k; pow3(k) ==> pow3(3*k);
  }

  lemma pow3_positive: \forall integer n; pow3(n) ==> n > 0;
  lemma pow3_factor: \forall integer a,m; pow3(m) && pow3(a*m) ==> pow3(a);
  lemma pow3_div3: \forall integer a; pow3(3*a) ==> pow3(a);
  lemma pow3_mod_property: \forall integer t; pow3(t) ==> (t == 1 || t % 3 == 0);
*/

int isPowerOfThree(int n);

/*@ 
  assigns \nothing;
  ensures (\result == 1) <==> pow3(n);
  ensures 0 <= \result <= 1;
*/
int isPowerOfThree(int n) {

        int temp = n;
        /*@ 
          loop invariant \exists integer m; m > 0 && pow3(m) && n == temp * m;
          loop invariant n >= 0 ==> temp >= 0;
          loop variant \abs(temp);
        */
        while (temp != 0 && temp % 3 == 0) {
            temp /= 3;
        }
        /*@ assert (temp == 1) <==> pow3(n); */
        return temp == 1;
}
