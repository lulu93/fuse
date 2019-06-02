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
    // int uid = getuid();
    // char* username = getlogin();
    // char username_read[100];
    // char key[16];
    // uint8_t input[1000];
    // uint8_t output[1000];
    // char* iv = "aaaabbbbccccdddd";
    // FILE* f;
    // if((f=fopen("/mnt/fuse/abc.txt", "r"))==NULL)
    // {
    // 	printf("Can not open file \n");
    // 	return 0;
    // }
    // fgets(username_read, strlen(username_read), stream);
    // //if (strcmp(username, username_read) == 0) {
    // fgets(key, strlen(key), stream);
    // uint32_t numread=fread(input, sizeof(uint8_t), 1000, f);
    // fclose(f);
    // if((f=fopen(path, "w"))==NULL);
    // AES128_CBC_decrypt_buffer(output, input, numread, (uint8_t*)key, (uint8_t*)iv);
    // int count = 0;
    // while (input[numread - count - 1] == 0) {
    // 	count ++;
    // }
    // fwrite(output, sizeof(uint8_t), numread - count, f);
    // fclose(f);
    // fclose(stream);
    return 0;
}
