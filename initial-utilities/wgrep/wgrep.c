#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if(argc==1){
        printf("wgrep: searchterm [file ...]\n");
        exit(1);
    }
    if(argc==2){
        //read from stdin
        char buffer[512];
        while(fgets(buffer, 512, stdin)!= NULL){
            if(strstr(buffer, argv[1])!=NULL){
                printf("%s",buffer);
            }
        }
        
        

    }
   for(int i=2; i<argc; i++){
        FILE *fp = fopen(argv[i],"r");
        if (fp==NULL){
            printf("wgrep: cannot open file\n");
            exit(1);   
        }

        char *line = NULL;
        size_t len = 0;
        while(getline(&line,&len,fp)!=-1){
            if(strstr(line, argv[1])!=NULL){
                printf("%s",line);
            }

        }

        fclose(fp);

   }
    exit(0);
}