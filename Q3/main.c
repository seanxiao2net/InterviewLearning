#include "stdio.h"
#include "stdlib.h"
#include "string.h"

const char base64_map[] ="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

size_t b64_length(size_t len)		//should return output length for the input of 'len' bytes.
{
	int pad = len%3;
	size_t size;
	size = (pad > 0) ? (len + 3 - pad) : len;
	return (size_t)(size*4)/3;
}

void b64_encode(const void * src, size_t len, void * dst)		//encode 'len' bytes from 'src' into 'dst'. 'dst' is guaranteed to hold at least b64_length('len') bytes.
{
	//define data buffers
	char *psrc = (char *)src;
	char *pdst = (char *)dst;
	size_t i=0;


	for (i=0; i< len; i+=3)
	{
		*pdst++ = base64_map[(*(psrc + i)>>2)&0x3f];
		*pdst++ = base64_map[((*(psrc + i)<<4)&0x30)|((*(psrc + i+1)>>4)&0x0F)];
		*pdst++ = base64_map[((*(psrc + i +1)<<2)&0x3C)|((*(psrc + i+2)>>6)&0x03)];
		*pdst++ = base64_map[((*(psrc + i +2))&0x3F)];
	}

	psrc += i;
	len -= i;

	if (len == 2)
	{
		*pdst++ = base64_map[(*(psrc + i)>>2)&0x3f];
		*pdst++ = base64_map[((*(psrc + i)<<4)&0x30)|((*(psrc + i+1)>>4)&0x0F)];
		*pdst++ = base64_map[((*(psrc + i +1)<<2)&0x3C)];
		*pdst++ = '=';
	}

	if (len == 1)
	{
		*pdst++ = base64_map[(*(psrc + i)>>2)&0x3f];
		*pdst++ = base64_map[((*(psrc + i)<<4)&0x30)];
		*pdst++ = '=';
		*pdst++ = '=';
	}
	*pdst++ = '\0';

}

int main()   
{   
    unsigned char src[3];  //00000000 01000101 11110010 in binary
	char * dst;
	char src_string[1024]; 
       
    src[0] = 0x00;   
    src[1] = 0x45;   
    src[2] = 0xf2;

	printf("length is %d\n",b64_length(3));

	dst = (char*)malloc( b64_length(strlen(src_string))+1);

	b64_encode(src,3,dst);

	printf("Convert 0x00 0x45 0xf2 to [%s]\n",dst);  

  
 
    getchar();   

	return 0;
   
}   
