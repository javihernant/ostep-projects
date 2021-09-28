#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>


void writeBytes(int *count, char* old_buffer, char* buffer){
    fwrite(count, sizeof(int),1,stdout);
    fwrite(old_buffer, sizeof(char),1,stdout);
    *count = 1;
    old_buffer[0] = buffer[0];
}

int main(int argc, char *argv[]) {

    if(argc==1){
        printf("wzip: file1 [file2 ...]\n");
        exit(1);
    }

    char old_buffer[1];
    char buffer[1];
    int count = 1;

    for(int i=1; i<argc; i++){
        FILE *fp = fopen(argv[i],"r");
        if (fp==NULL){
            printf("wzip: cannot open file\n");
            exit(1);   
        }

        if(i==1) fread(old_buffer,sizeof(char),1,fp);

        while(fread(buffer,sizeof(char),1,fp)!=0){
            if(buffer[0] == old_buffer[0]){
                count++;
            }else{

                writeBytes(&count, old_buffer, buffer);
                
                
            }
        }

        if(i==argc-1){
            writeBytes(&count, old_buffer, buffer);
        }


        fclose(fp);
    }


    return 0;
}