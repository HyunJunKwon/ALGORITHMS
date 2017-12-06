// Header files inclusion
#include <stdio.h>
#include <stdlib.h>


// Define constant
#define SIZE 10000

// Union declare
typedef union
{
	unsigned int num;
	char arr[4];
}ENDIAN;

unsigned int Convert(unsigned int value);

int main(void)
{
	// Local variables declare
	int key;
	int i;
	unsigned int num;
	unsigned int * result;
	
	// Statements
	scanf_s("%d", &key);
	result = (unsigned int *)malloc(sizeof(unsigned int) * key);

	for (i = 0; i < key; i++)
	{
		scanf_s("%d", &num);
		*(result + i) = Convert(num);
	}
	
	for (i = 0; i < key; i++)
	{
		printf("%u\n", *(result + i));
	}

	free(result);
	
	return 0;
}
unsigned int Convert(unsigned int value)
{
	char temp;
	ENDIAN NUMBER;
	NUMBER.num = value;

	temp = NUMBER.arr[3];
	NUMBER.arr[3] = NUMBER.arr[0];
	NUMBER.arr[0] = temp;

	temp = NUMBER.arr[2];
	NUMBER.arr[2] = NUMBER.arr[1];
	NUMBER.arr[1] = temp;

	return (NUMBER.num);

}