int calculate(int num1, int num2, char operator);

/*@ 
  assigns \nothing;

  behavior add:
    assumes operator == '+';
    requires (num2 >= 0 ==> num1 <= INT_MAX - num2) &&
             (num2 <= 0 ==> num1 >= INT_MIN - num2);
    ensures \result == num1 + num2;

  behavior sub:
    assumes operator == '-';
    requires (num2 >= 0 ==> num1 >= INT_MIN + num2) &&
             (num2 <= 0 ==> num1 <= INT_MAX + num2);
    ensures \result == num1 - num2;

  behavior mul:
    assumes operator == '*';
    requires num2 == 0 || num1 == 0 ||
             (num2 > 0 && num1 >= INT_MIN / num2 && num1 <= INT_MAX / num2) ||
             (num2 < 0 && num1 <= INT_MIN / num2 && num1 >= INT_MAX / num2);
    ensures \result == num1 * num2;

  behavior div:
    assumes operator == '/';
    requires num2 != 0;
    requires !(num1 == INT_MIN && num2 == -1);
    ensures \result == num1 / num2;

  behavior mod:
    assumes operator == '%';
    requires num2 != 0;
    requires !(num1 == INT_MIN && num2 == -1);
    ensures \result == num1 % num2;
    ensures \abs(\result) < \abs(num2);

  behavior invalid:
    assumes operator != '+' && operator != '-' && operator != '*' && operator != '/' && operator != '%';
    ensures \result == -1;

  complete behaviors;
  disjoint behaviors;
*/
int calculate(int num1, int num2, char operator) {

        int output;

        switch (operator)
        {
            case '+':
            	output = num1 + num2;
                break;

            case '-':
            	output = num1 - num2;
                break;

            case '*':
            	output = num1 * num2;
                break;

            case '/':
            	output = num1 / num2;
		break;

	    case '%':
		output = num1 % num2;
                break;

            default:
                return -1;
        }
        return output;
}
