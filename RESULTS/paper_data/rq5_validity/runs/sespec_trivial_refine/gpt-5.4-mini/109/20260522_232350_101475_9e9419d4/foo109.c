int foo109(int n);


/*@
  assigns \nothing;
  ensures (\result == 8) <==> (n % 3 == 0 && n % 5 == 0);
  ensures (\result == 3) <==> (n % 3 == 0 && n % 5 != 0);
  ensures (\result == 5) <==> (n % 3 != 0 && n % 5 == 0);
  ensures (\result == 0) <==> (n % 3 != 0 && n % 5 != 0);
  ensures \result == ((n % 3 == 0) ? 3 : 0) + ((n % 5 == 0) ? 5 : 0);
*/
int foo109(int n) {

        int res = 0;
        res += ((n % 3 == 0) ? 3 : 0);
        res += ((n % 5 == 0) ? 5 : 0);
        return res;
}