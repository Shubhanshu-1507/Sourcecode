#include <stdio.h>

int main() {
  char gender;
  printf("Enter You Gender: M/F:\n");
  scanf("%c", &gender);
  switch (gender) {
  case 'M':
    printf("Male");
    break;
  case 'm':
    printf("Male");
    break;
  case 'F':
    printf("Female");
    break;
  case 'f':
    printf("Female");
    break;
  default:
    printf("Invalid Input");
    break;
  }
}
