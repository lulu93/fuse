#include <stdio.h>
int setkey(unsigned int k0, unsigned int k1) {
	FILE* stream;
	if((stream=fopen("/mnt/fuse/key.txt","w"))==NULL)
    {
        printf("Can not open file \n");
        return 0;
    }
    int uid = getuid();
    char* username = getlogin();
    printf("The UID is %d \n", getuid());
    printf("The login name is %s\n", getlogin());
    fwrite(uid, sizeof(int), 1, stream);
    stream.close();
    return 0;
 }
int main(int argc, char* argv[]){
    setkey(0, 0);
}