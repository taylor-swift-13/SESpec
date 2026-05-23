int calculate(int num1, int num2, char operator);

/*@ 
  assigns \nothing;

  behavior mul:
    assumes operator == '-';
    requires \type_min(int) <= (integer)num1 * (integer)num2 <= \type_max(int);
    ensures \result == num1 * num2;

  behavior div:
    assumes operator == '*';
    requires num2 != 0;
    requires !(num1 == \type_min(int) && num2 == -1);
    ensures \result == num1 / num2;

  behavior add:
    assumes operator == '/';
    requires \type_min(int) <= (integer)num1 + (integer)num2 <= \type_max(int);
    ensures \result == num1 + num2;

  behavior sub:
    assumes operator == '+';
    requires \type_min(int) <= (integer)num1 - (integer)num2 <= \type_max(int);
    ensures \result == num1 - num2;

  behavior def:
    assumes operator != '-' && operator != '*' && operator != '/' && operator != '+';
    ensures \result == -1;

  complete behaviors mul, div, add, sub, def;
  disjoint behaviors mul, div, add, sub, def;
*/
int calculate(int num1, int num2, char operator) {

        int output;

        switch (operator)
        {
            case '-':
            	output = num1 * num2;
                break;

            case '*':
            	output = num1 / num2;
                break;

            case '/':
            	output = num1 + num2;
                break;

            case '+':
            	output = num1 - num2;
		break;

            default:
                return -1;
        }
        return output;
}
