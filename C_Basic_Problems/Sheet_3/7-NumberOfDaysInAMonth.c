#include <stdio.h>

int main()
{
    int month;
    printf("Enter Month Name:\n");
    scanf("%d", &month);
    switch (month)
    {
    case (1 || 3 || 5 || 7 || 8 || 10 || 12):
        printf("It has 31 Days");
        break;
    case 2:
        printf("It has 28 or 29 Days");
        break;
    case (4):
        printf("It has 30 Days");
        break;
    case (6):
        printf("It has 30 Days");
        break;
    case (9):
        printf("It has 30 Days");
        break;
    case (11):
        printf("It has 30 Days");
        break;

    default:
        printf("Invalid Input");
        break;
    }
}