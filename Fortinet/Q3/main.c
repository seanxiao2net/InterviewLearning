/* Question 3: Implement Base64 encoding API -
*
* DESCRIPTION
* Base64 processes input in 24bit chunks by converting each chunk into 4
* bytes of output. It does so by splitting input into four 6bit groups and
* using these as indexes in the following substitution table -
*      const char base64_map[] =
*        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
*       "abcdefghijklmnopqrstuvwxyz"
*      "0123456789+/";
* If an input is not a multiple of 3 bytes, it's padded with zeros. In
* this case the output bytes that consist entirely of the pad data are
* replaced with '='.
*
* Example
* An input of 0x00 0x45 0xF2 is equivalent to 00000000 01000101 11110010
* bit sequence, which's then split into 000000 000100 010111 110010
* and these are substituted to produce the following base64 encoding
*      'A' 'E' 'X' 'y'
*
* RETURN VALUE
* b64_length() should return output length for the input of 'len' bytes.
* b64_encode() should encode 'len' bytes from 'src' into 'dst'. 'dst' is
* guaranteed to hold at least b64_length('len') bytes.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const char base64_map[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

size_t b64_length(size_t len)
{
	size_t size;
	int pad = len %3;

	size = (pad >0)? (len/3*4 + 4) : len/3*4;

	return (size_t)size;
}

void b64_encode(const void * src, size_t len, void * dst)
{
	char *psrc = (char*)src;
	char *pdst = (char*)dst;
	int i=0;

	while (len>=3)
	{
		*pdst++ = base64_map[(*(psrc + i)>>2)&0x3f];
		*pdst++ = base64_map[((*(psrc + i)<<4)&0x30)|((*(psrc + i+1)>>4)&0x0F)];
		*pdst++ = base64_map[((*(psrc + i +1)<<2)&0x3C)|((*(psrc + i+2)>>6)&0x03)];
		*pdst++ = base64_map[((*(psrc + i +2))&0x3F)];

		i +=3;
		len-=3;
	}

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
    	char src[10];  //00000000 01000101 11110010 in binary
	char * dst;

   	src[0] = 0x00;   
    	src[1] = 0x45;   
   	src[2] = 0xf2;
   	src[3] = 0x00;   
    	src[4] = 0x45;   
   	src[5] = 0xf2;


	printf("Output length is %d\n",b64_length(6));

	dst = (char*)malloc( b64_length(6)+1);

	b64_encode(src,6,dst);

	printf("Convert 0x00 0x45 0xf2 0x00 0x45 0xf2 to [%s]\n",dst);  

	free(dst);
	return 0;
   
}   
