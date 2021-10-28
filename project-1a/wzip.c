#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
   if(argc < 2) {
      printf("wzip: file1 [file2 ...]\n");
      exit(1);
   }

   int j, ch, curr;
   int count = 0;
   for(j = 1; j < argc; j++) {
      FILE *fp = fopen(argv[j], "r");
      if(fp == NULL) {
         printf("wzip: cannot open file\n");
         exit(1);
      }
      
      while((ch = getc(fp)) != EOF) {
         if(count == 0) {
            count = 1;
            curr = ch;
            continue;
         }
         if(ch != curr) {
            fwrite(&count, sizeof(int), 1, stdout);
            fwrite(&curr, sizeof(char), 1, stdout);
            curr = ch;
            count = 1;
         } else 
            count++;
      }
      fclose(fp);
   }

   fwrite(&count, sizeof(int), 1, stdout);
   fwrite(&curr, sizeof(char), 1, stdout);
   
   return 0;
}