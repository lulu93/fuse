#ifndef AES_H
  #define AES_H
#endif
	
#include <stdint.h>
#include <string.h> // CBC mode, for memset
#include <stdio.h>

#define ECB 1
#define CBC 1

#if defined(CBC) && CBC
  static void XorWithIv(uint8_t* buf);
  void AES128_CBC_encrypt_buffer(uint8_t* output, uint8_t* input, uint32_t length, const uint8_t* key, const uint8_t* iv);
  void AES128_CBC_decrypt_buffer(uint8_t* output, uint8_t* input, uint32_t length, const uint8_t* key, const uint8_t* iv);
#endif

#if defined(ECB) && ECB
void AES128_ECB_encrypt(const uint8_t* input, const uint8_t* key, uint8_t* output);
void AES128_ECB_decrypt(const uint8_t* input, const uint8_t* key, uint8_t *output);
#endif
