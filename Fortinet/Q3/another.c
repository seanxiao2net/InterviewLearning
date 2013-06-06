#include "stdio.h"   
#include "stdlib.h"   
#include "string.h"   
   
const char base64_map[] ="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";   
   
size_t b64_length(size_t len)   
{   
    int npad = len%3;   
    size_t  size = (npad > 0)? (len +3-npad ) : len; // padded for multiple of 3 bytes   
    return  (size*8)/6;   
}   
   
void b64_encode(const void * src, size_t len, void * dst)   
{   
    char *srcp = (char *)src;   
    char *dstp = (char *)dst;   
   
    int pad_len = len%3,new_len;//length after padded   
    if(pad_len != 0){   
        pad_len = 3 - pad_len;   
        new_len = len+pad_len;   
    }   
    else   
        new_len = len;   
   
    unsigned char byte4[4],*bit24= &byte4[0], left;   
    register int i = 0,j=0, k = 0;   
   
    while( k < new_len){   
   
        *bit24++ = (k++ < len) ? *srcp++ : 0;   
   
        if(i++ == 2) // 3 Bytes are ready for encoding 3*8   
        {   
            bit24 -= 3; //go back to the byte4[0]   
            for(j = 0; j < 4; j++)   
            {   
                switch (j)   
                {   
                    case 0:   
                    *dstp++ = base64_map[(*bit24>>2)&0x3f];   
                    left = (bit24[0] << 4)&& 0x30 ;   
                    break;   
                    case 1:   
                    *dstp++ = base64_map[(left+(*(bit24+1)>>4))&0x3f];   
                    left = (bit24[1] << 2)&0x36;   
                    break;   
                    case 2:   
                    *dstp++ = base64_map[(left+(*(bit24+2)>>6))&0x3f];   
                    break;   
                    case 3:   
                    *dstp++ = base64_map[*(bit24+2)&0x3f];   
                    break;   
                }   
            }   
            i = 0;   
        }   
    }   
    if(pad_len == 1)  //padded 1 bytes '='   
        *(dstp-1) = '=';   
    else if(pad_len == 2) //padded 2 bytes of '='   
    {   
        *(dstp-1) = '=';   
        *(dstp-2) = '=';   
    }   
    *dstp = '\0';   
}   
   
main()   
{   
    unsigned char src[6];  //00000000 01000101 11110010 in binary   
       
    src[0] = 0x00;   
    src[1] = 0x45;   
    src[2] = 0xf2; 
    src[3] = 0x00;   
    src[4] = 0x45;   
    src[5] = 0xf2;     
   
    char* dst = (char*)malloc( b64_length(6)+1);   
    if(dst == NULL)   
        return;   
   
    b64_encode(src,5,dst);   
    printf("Convert string [0x00 0x45 0xf2]  to [%s]\n",dst);   
    printf("Try to encode another string(q exit) ,input: \n",dst);   
    free(dst);   
   
    char src_string[1024];   
    while(1) {   
        scanf("%s",src_string);   
        if(src_string[0] == 'q')   
            break;   
        dst = (char*)malloc( b64_length(strlen(src_string))+1);   
        if(dst == NULL)   
            break;   
        b64_encode(src_string,strlen(src_string),dst);   
        printf("Encoded string is [%s]\n",dst);   
        free(dst);   
    }   
   
    getchar();   
   
}   
