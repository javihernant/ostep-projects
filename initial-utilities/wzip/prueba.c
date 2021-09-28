
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    // int c=91;
    // fwrite(&c, sizeof(int),1,stdout);

    char b1[1];
    char b2[1];
    FILE *fp = fopen(argv[1],"r");
    if (fp==NULL){
        printf("wzip: cannot open file\n");
        exit(1);   
    }

    fread(b1,sizeof(char),1,fp);
    fread(b2,sizeof(char),1,fp);

    printf("%c",b1[0]);
    printf("%c",b2[0]);

    return 0;
}