#include <stdio.h>
#include <stdlib.h>
#define BUFFER_SIZE 256

int main(int argc, char *argv[]) 
{
   int i;
   char buffer[BUFFER_SIZE];
   for(i = 1; i < argc; i++) 
   {
      FILE *fp = fopen(argv[i], "r");
      if(fp == NULL) 
      {
         printf("wcat: cannot open file\n");
         exit(1);
      }

      while(fgets(buffer, BUFFER_SIZE, fp)) 
      {
         printf("%s", buffer);
      }
   }
   
   return 0;
}