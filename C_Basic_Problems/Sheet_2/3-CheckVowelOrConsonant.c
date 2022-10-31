#include <stdio.h>

int main() {
  char c;
  int small, big;
  scanf("%c", &c);
  small = (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');

  big = (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
  if (small || big) {
    printf("%c is a Vowel", c);
  } else {
    printf("%c is a Consonant", c);
  }
}
