// include 
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

char * encrypt_arg(char *data)
{
  int key;

  srand(time(NULL));

  key = '=';

  for (int i = 0; i < strlen(data); i++)
  {
    data[i] = data[i] ^ key;
  }

  return data;
}

int main(int argc, char *argv[])
{
  int i = 0;
  char *data;
  char buffer[10];
  char password[10];

  while(1){

    printf("Password: ");

    scanf("%10s", password);

    buffer[7] = 'd';
    buffer[3] = 'I';
    buffer[8] = 'e';
    buffer[0] = 'S';
    buffer[9] = '\0';
    buffer[1] = 'e';
    buffer[4] = 'n';
    buffer[6] = 'i';
    buffer[2] = 'c';
    buffer[5] = 's';

    data = encrypt_arg(password);

    if (strcmp(data,buffer) != 0)
    {
      printf("Nice try, but nope\n");
    }
    else
    {
      printf("Yey!\n");
    }
  }

  return 0;
}