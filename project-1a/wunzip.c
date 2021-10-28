#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
   if(argc < 2) {
      printf("wunzip: file1 [file2 ...]\n");
      exit(1);
   }

   int j;
   for(j = 1; j < argc; j++) {
      FILE *fp = fopen(argv[j], "r");
      if(fp == NULL) {
         printf("wunzip: cannot open file\n");
         exit(1);
      }
      int count;
      while(fread(&count, sizeof(int), 1, fp) > 0) {
         int i;
         char curr;
         fread(&curr, sizeof(char), 1, fp);
         for(i = 0; i < count; i++) {
            fwrite(&curr, sizeof(char), 1, stdout);
         }
      }
      fclose(fp);
   }
   
   return 0;
}