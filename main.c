#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt_string(char* input_string, int shift_key);

#define INPUT_MAX_LENGTH 30

int main(int argc, char* argv[])
{
  if (argc != 3)
  {
    printf("Usage: %s [string to be encrypted] [shift key value]\n",
        argv[0]);

    return 1;
  }

  char user_input[INPUT_MAX_LENGTH];
  if (strlen(argv[1]) > INPUT_MAX_LENGTH)
  {
    printf("Max length of string to be encrypted: %d\n",
        INPUT_MAX_LENGTH);

    return 1;
  }

  strncpy(user_input, argv[1], sizeof(user_input));

  int shift_key;
  if (sscanf(argv[2], "%d", &shift_key) != 1)
  {
    printf("Please provide an integer for the shift key value\n");

    return 1;
  }

  encrypt_string(user_input, shift_key);

  printf("Encrypted string: %s\n", user_input);

  return 0;
}

void encrypt_string(char* input_string, int shift_key)
{
  int i = 0;

  while (input_string[i] != '\0')
  {
    if (input_string[i] >= 'A' && input_string[i] <= 'Z')
      input_string[i] = (input_string[i] + shift_key - 'A') % 26 + 'A';
    else if (input_string[i] >= 'a' && input_string[i] <= 'z')
      input_string[i] = (input_string[i] + shift_key - 'a') % 26 + 'a';
    else if (input_string[i] != ' ' && input_string[i] != '\n')
      printf("Ignoring non-alphabetic character: %c\n", input_string[i]);
    else
      input_string[i] = ' ';

    i++;
  }
}
