//#include <sys/types.h>
//#include <sys/stat.h>
#include "aes.h"
int main(int argc,char* argv[]) {
	if (argc != 4) {
		printf("please enter the correct parameter!");
		printf("-e/-d key file");
		return 0;
	}
	uint8_t input[1000];
	uint8_t output[1000];
	char* iv = "aaaabbbbccccdddd";
	FILE* stream;
	FILE* stream_out;
	if((stream=fopen(argv[3],"r"))==NULL)
    {
		
        printf("Can not open file \n");
        return 0;
    }
	if (argv[1][1] == 'e') {
		
		uint32_t numread=fread(input, sizeof(uint8_t), 1000, stream);
		printf("numread = %d\n", numread);

		fclose(stream);
		int remain = numread % 16; 
		int length = numread;
		if (remain != 0) {
			for (int i = 0; i < 16 - remain; i++) {
				//input[numread + i] = uint8_t('0');
				length++;
			}
		} 
		printf("input = %s\n", input);
		//AES128_ECB_encrypt(input, (uint8_t*)argv[2], output);
		AES128_CBC_encrypt_buffer(output, input, numread, (uint8_t*)argv[2], (uint8_t*)iv);
		if((stream=fopen(argv[3],"w"))==NULL)
	    {
			
	        printf("Can not open file \n");
	        return 0;
	    }
		printf("output = %s\n", output);
		fwrite(output, sizeof(uint8_t), length, stream);
		fclose(stream);
	} 
	else if (argv[1][1] == 'd') { 
		uint32_t numread=fread(input, sizeof(uint8_t), 1000, stream);
		printf("numread = %d\n", numread);
		printf("input = %s\n", input);
		fclose(stream);
		//AES128_ECB_decrypt(input, (uint8_t*)argv[2], output);
		AES128_CBC_decrypt_buffer(output, input, numread, (uint8_t*)argv[2], (uint8_t*)iv);
		if((stream=fopen(argv[3],"w"))==NULL)
	    {
			
	        printf("Can not open file \n");
	        return 0;
	    }
		printf("output = %s\n", output);
		int count = 0;
		while (input[numread - count - 1] == 0) {
			count ++;
		}

		printf("count = %d\n", count);
		fwrite(output, sizeof(uint8_t), numread - count, stream);
		fclose(stream);
    }
    else {
    	printf("please enter the correct parameter!");
	}


    return 0;
}
