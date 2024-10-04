#include <stdio.h>

int main()
{
    int WeekDay_Num;
    printf("Enter Weekday Number:\n");
    scanf("%d", &WeekDay_Num);
    switch (WeekDay_Num)
    {
    case 1:
        printf("Sunday");
        break;
    case 2:
        printf("Monday");
        break;
    case 3:
        printf("Tuesday");
        break;
    case 4:
        printf("Wednesday");
        break;
    case 5:
        printf("Thursday");
        break;
    case 6:
        printf("Friday");
        break;
    case 7:
        printf("Saturday");
        break;

    default:
        printf("Wrong Input");
        break;
    }
}