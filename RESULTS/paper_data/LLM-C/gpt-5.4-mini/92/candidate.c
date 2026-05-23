/*@
    requires operator == '+' || operator == '-' || operator == '*' || operator == '/' || operator == '%';
    requires operator != '/' || num2 != 0;
    requires operator != '%' || num2 != 0;
    assigns \nothing;
    ensures operator == '+' ==> \result == num1 + num2;
    ensures operator == '-' ==> \result == num1 - num2;
    ensures operator == '*' ==> \result == num1 * num2;
    ensures operator == '/' ==> \result == num1 / num2;
    ensures operator == '%' ==> \result == num1 % num2;
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
