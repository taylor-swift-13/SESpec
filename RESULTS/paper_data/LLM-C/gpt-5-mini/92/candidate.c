/*@
    requires (operator == '/' || operator == '%') ==> num2 != 0;
    assigns \nothing;
    behavior plus:
        assumes operator == '+';
        ensures \result == num1 + num2;
    behavior minus:
        assumes operator == '-';
        ensures \result == num1 - num2;
    behavior mul:
        assumes operator == '*';
        ensures \result == num1 * num2;
    behavior div:
        assumes operator == '/';
        ensures \result == num1 / num2;
    behavior mod:
        assumes operator == '%';
        ensures \result == num1 % num2;
    behavior default:
        assumes operator != '+' && operator != '-' && operator != '*' && operator != '/' && operator != '%';
        ensures \result == -1;
    complete behaviors plus, minus, mul, div, mod, default;
    disjoint behaviors plus, minus, mul, div, mod, default;
*/
int calculate(int num1, int num2, char operator);

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
