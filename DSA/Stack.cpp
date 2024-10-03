#include <bits/stdc++.h>
using namespace std;

struct node
{
    char data;
    node *next;
};

struct MyStack
{
    node *top;
    MyStack()
    {
        top = NULL;
    }
    void push(char value)
    {
        node *newnode = new node();
        newnode->data = value;
        newnode->next = top;
        top = newnode;
    }
    bool isEmpty()
    {
        return top == NULL;
    }
    char pop()
    {
        if (isEmpty())
        {
            cout << "UNDERFLOW !!!" << endl;
            return '\0';  // Changed to '\0'
        }
        node *temp = top;
        char popValue = temp->data;
        top = top->next;
        delete temp;
        return popValue;
    }
    char peek()
    {
        if (isEmpty())
        {
            cout << "Stack is empty" << endl;
            return '\0';  // Changed to '\0'
        }
        return top->data;
    }
};

bool isOperator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    else if (op == '*' || op == '/')
        return 2;
    return 0;
}

string infixtopostfix(string infix)  // Moved before infixtoprefix
{
    MyStack s;
    string postfix = "";
    for (char &ch : infix)
    {
        if (isalnum(ch))
        {
            postfix += ch;
        }
        else if (ch == '(')
        {
            s.push(ch);
        }
        else if (ch == ')')
        {
            while (!s.isEmpty() && s.peek() != '(')
            {
                postfix += s.pop();
            }
            if (!s.isEmpty())
            {
                s.pop();
            }
        }
        else if (isOperator(ch))
        {
            while (!s.isEmpty() && precedence(s.peek()) >= precedence(ch))
            {
                postfix += s.pop();
            }
            s.push(ch);
        }
    }
    while (!s.isEmpty())
    {
        postfix += s.pop();
    }
    return postfix;
}

string infixtoprefix(string infix)
{
    reverse(infix.begin(), infix.end());
    for (int i = 0; i < infix.length(); i++)
    {
        if (infix[i] == '(')
        {
            infix[i] = ')';
        }
        else if (infix[i] == ')')
        {
            infix[i] = '(';
        }
    }
    string postfix = infixtopostfix(infix);
    reverse(postfix.begin(), postfix.end());
    return postfix;
}

int evalPostFix(string postfix)
{
    stack<int> eval;
    for (char &ch : postfix)
    {
        if (isdigit(ch))
        {
            eval.push(ch - '0');
        }
        else
        {
            int operand2 = eval.top();
            eval.pop();
            int operand1 = eval.top();
            eval.pop();
            switch (ch)
            {
            case '+':
                eval.push(operand1 + operand2);
                break;
            case '-':
                eval.push(operand1 - operand2);
                break;
            case '*':
                eval.push(operand1 * operand2);
                break;
            case '/':
                if (operand2 == 0)
                {
                    cout << "denominator is zero!!!!" << endl;
                    return -1;
                }
                eval.push(operand1 / operand2);
                break;
            }
        }
    }
    return eval.top();
}

int evalprefix(string prefix)
{
    stack<int> eval;
    for (int i = prefix.length() - 1; i >= 0; i--)
    {
        if (isdigit(prefix[i]))
        {
            eval.push(prefix[i] - '0');
        }
        else
        {
            int operand1 = eval.top();
            eval.pop();
            int operand2 = eval.top();
            eval.pop();
            switch (prefix[i])
            {
            case '+':
                eval.push(operand1 + operand2);
                break;
            case '-':
                eval.push(operand1 - operand2);
                break;
            case '*':
                eval.push(operand1 * operand2);
                break;
            case '/':
                eval.push(operand1 / operand2);
                break;
            }
        }
    }
    return eval.top();
}

int main()
{
    int choice;
    string infix, postfix, prefix, expression;

    do
    {
        cout << "-------------menu----------------" << endl;
        cout << "1. Convert Infix to Postfix" << endl;
        cout << "2. Convert Infix to Prefix" << endl;
        cout << "3. Evaluate Postfix Expression" << endl;
        cout << "4. Evaluate Prefix Expression" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();  // Ignore newline character after choice input

        switch (choice)
        {
        case 1:
            cout << "Enter infix expression: ";
            getline(cin, infix);  // Use getline for full input
            postfix = infixtopostfix(infix);
            cout << "Postfix Expression: " << postfix << endl;
            break;

        case 2:
            cout << "Enter infix expression: ";
            getline(cin, infix);  // Use getline for full input
            prefix = infixtoprefix(infix);
            cout << "Prefix Expression: " << prefix << endl;
            break;

        case 3:
            cout << "Enter postfix expression: ";
            getline(cin, expression);  // Use getline for full input
            cout << "Postfix Evaluation Result: " << evalPostFix(expression) << endl;
            break;

        case 4:
            cout << "Enter prefix expression: ";
            getline(cin, expression);  // Use getline for full input
            cout << "Prefix Evaluation Result: " << evalprefix(expression) << endl;
            break;

        case 5:
            cout << "Exiting program." << endl;
            break;

        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    } while (choice != 5);

    return 0;
}
