#include <stdio.h>
#include <stdlib.h>
int setkey(char* k0, char* k1) {
	FILE* stream;
	if((stream=fopen("/mnt/fuse/key","w"))==NULL)
    {
        printf("Can not open file key\n");
        return 0;
    }
    int uid = getuid();
    char* username = getlogin();
    printf("The UID is %d \n", getuid());
    printf("The login name is %s\n", getlogin());
    char space = '\n';
    fwrite(username, sizeof(char), strlen(username), stream);
    fwrite(&space, sizeof(char), 1, stream);
    fwrite(k0, sizeof(char), strlen(k0), stream);
    fwrite(k1, sizeof(char), strlen(k1), stream);
    fclose(stream);
    return 0;
 }
int main(int argc, char* argv[]){
    setkey(argv[1], argv[2]);
    return 0;
}
