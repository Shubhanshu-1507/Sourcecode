// Infix to postfix conversion program
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct stack{
    int size;
    int top;
    char *array;
};
int isFull(struct stack *ptr)
{
    if(ptr->top ==ptr->size-1)
    {
        printf("The stack is full\n");
        return 1;
    }else{
        return 0;
    }
}
int isEmpty(struct stack *ptr)
{
    if(ptr->top ==-1)
    {
        printf("The stack is empty\n");
        return 1;
    }else{
        return 0;
    }
}
void push(struct stack *ptr,char value)
{
    if(isFull(ptr))
    {
        printf("The element cannot be inserted as the stack is full\n");
    }else{
        ptr->top++;
        ptr->array[ptr->top]=value;
    }
}
char pop(struct stack *ptr)
{
    if(isEmpty(ptr))
    {
        printf("The element cannot be popped as the stack is empty\n");
        return '$';
    }else{
        char c;
        c=ptr->array[ptr->top];
        ptr->top--;
        return c;
    }
}
char stackTop(struct stack *ptr)
{
    return ptr->array[ptr->top];
}
int operator(char a)
{
    if(a =='+' || a=='-' || a=='*' || a=='/')
    {
        return 1;
    }
    else{
        return 0;
    }
}
int precedence(char a)
{
    if(a== '*' || a=='/')
    {
        return 2;
    }
    if(a=='+' || a=='-')
    {
        return 1;
    }
    else{
        return 0;
    }
}
char * infixtopostfix(struct stack *s,char *infix)
{
char *postfix= (char *)malloc(strlen(infix)+1 * sizeof(char));
int i=0;
int j=0;
while(infix[i]!='\0')
{
    if(!(operator(infix[i])))
    {
        postfix[j]=infix[i];
        i++;
        j++;
    }
    else{
        if(precedence(infix[i]) > precedence(stackTop(s)))
        {
            push(s,infix[i]);
            i++;
        }else{
            postfix[j]=pop(s);
            j++;
        }
    }
    
} while(!isEmpty(s))
    {
        postfix[j]=pop(s);
        j++;
    }
    postfix[j]='\0';
    return postfix;
}
int main()
{
   // struct stack *s=(struct stack *)malloc(sizeof(struct stack));
   struct stack *s;
    s->top=-1;
    s->size=50;
    s->array=(char *)malloc(s->size * sizeof(char));
    char *infix;
    // infix
    infix= "x+y*z-k";
    printf("The postfix of the infix expression is %s\n",infixtopostfix(s,infix));

    return 0;
}
