void infixToPostfix(char* expn,char* output)
{
Stack stk;
StackInitialize(&stk);
char ch, op;
int i = 0;
int index =0;
int digit = 0;
while ((ch = expn[i++]) != '\0')
{
if (isdigit(ch))
{
output[index++] = ch;
digit=1;
}
else
{
if(digit)
{
output[index++] = ' ';
digit = 0;
}
switch (ch)
{
case '+':
case '-':
case '*':
case '/':
case '%':
case '^':
while (!StackIsEmpty(&stk) && precedence(ch) <= precedence(StackTop(&stk)))
{
op = StackPop(&stk);
output[index++] = op;
output[index++] = ' ';
}
StackPush(&stk, ch);
break;
case '(':
StackPush(&stk, ch);
break;
case ')':
while (!StackIsEmpty(&stk) && (op = StackPop(&stk)) != '(')
{
output[index++] = op;
output[index++] = ' ';
}
break;
}
}
}
while (!StackIsEmpty(&stk))
{
op = StackPop(&stk);
output[index++] = op;
output[index++] = ' ';
}
output[index++] = '\0';
}
int precedence(char x)
{
if (x == '(')
return(0);
if (x == '+' || x == '-')
return(1);
if (x == '*' || x == '/' || x == '%')
return(2);
if (x == '^')
return(3);
return(4);
}
