#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#define BUFFER_SIZE 256

int main(int argc, char *argv[]) {
   char *buffer = NULL;
   size_t buff_size = 0;

   if(argc < 2) {
      printf("wgrep: searchterm [file ...]\n");
      exit(1);
   }

   char* matching = argv[1];

   if(argc == 2) {
      while(getline(&buffer, &buff_size, stdin) >= 0) {
           if(strstr(buffer, matching) != NULL)
                  printf("%s", buffer);
      }
   } else {
         int i;
         for(i = 2; i < argc; i++) {
            FILE *fp = fopen(argv[i], "r");
            if(fp == NULL) {
               printf("wgrep: cannot open file\n");
               exit(1);
            }

            while(getline(&buffer, &buff_size, fp) >= 0) {
               if(strstr(buffer, matching) != NULL)
                  printf("%s", buffer);
            }
         }
   }

   free(buffer);
   buffer = NULL;

   return 0;
}
