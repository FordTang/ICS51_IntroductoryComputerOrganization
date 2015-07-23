#include<malloc.h>
#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//when you want to test one of the parts of the assignment, just change the 0 into a 1 for
//the constant corresponding to that part
#define POSITIVE_SUM 1
#define TOUPPER 1
#define ISPRIME 1

extern char *yourName;
extern char *studentID;

extern int positiveSum(int *str, int len);
extern void toUpper(char *str);
extern int isPrime(unsigned int x);

void testPositiveSum(int *Arr, int len);
void checkUpper(char *str);
int checkPrime(unsigned int x);

void main()
{
	int i;

#if POSITIVE_SUM
	int * Arr;
#endif

#if TOUPPER
	char *test2[5]={"Hello, World!", "ABCDEFG", "", "12345", "~!@#$"};
#endif

#if ISPRIME
	unsigned test3[10]={0, 1, 2, 3, 10, 121, 97, 169, 3571, 3590989};
#endif

	printf("ICS 51 Summer 2013 - Lab 2\n\n");
	printf("Name: %s\n", yourName);
	printf("Student ID: %s\n\n", studentID);
	
#if POSITIVE_SUM
	Arr = (int*)malloc(sizeof(int));
	Arr[0] = 0;
	testPositiveSum(Arr, 1);
	free(Arr);

	Arr = (int*)malloc(sizeof(int)*5);
	for(i = 0; i < 5; i++) {
		Arr[i] = -1;
	}
	testPositiveSum(Arr, 5);
	
	for(i = 0; i < 5; i++) {
		Arr[i] = 1;
	}
	testPositiveSum(Arr, 5);

	for(i = 0; i < 5; i++) {
		Arr[i] = i * 5 - 10;
	}
	testPositiveSum(Arr, 5);

	free(Arr);
#endif

#if TOUPPER
	for(i = 0; i < 5; i++) {
		checkUpper(test2[i]);
	}
#endif

#if ISPRIME
	for(i = 0; i < 10; i++) {
		printf("%u: %u\n", test3[i], isPrime(test3[i]));
		if(checkPrime(test3[i])) {
			printf("%u is a prime number. %u", test3[i]);
			if(isPrime(test3[i])) {
				printf(" And your function agrees.\n\n");
			} else {
				printf(" But your function is WRONG******XXXXXX******.\n\n");
			}
		} else {
			printf("%u is not a prime number.", test3[i]);
			if(isPrime(test3[i])) {
				printf(" But your function is WRONG******XXXXXX******.\n\n");
			} else {
				printf(" And your function agrees.\n\n");
			}
		}
	}
#endif

	system("PAUSE");
}

#if POSITIVE_SUM
void testPositiveSum(int *Arr, int len) {
	int i;
	int correct = 0;
	int result;

	if (len <= 0) return;

	printf("Testing array: ");
	printf("%d", Arr[0]);

	for (i = 1; i < len; i++) {
		printf(", %d", Arr[i]);
	}
	printf(".\n");

	for(i = 0; i < len; i++) {
		if(Arr[i] > 0) {
			correct += Arr[i];
		}
	}

	result = positiveSum(Arr, len);

	if (correct == result) {
		printf("Your answer is %d, and it is correct.\n", result);
	} else {
		printf("Your answer is %d, but the correct one should be %d\n", result, correct);
	}
}
#endif
#if TOUPPER
void checkUpper(char *str){

	char buff[30], *p;

	if(str==NULL) {
		return;
	}

	strcpy_s(buff, 29, str);

	printf("Original string: %s\n", buff);
	toUpper(buff);
	printf("Called toUpper: %s\n", buff);

	for (p=buff; *p; p++) {
		if(*p != toupper(*p)) {
			printf("***ERROR FOUND***.\n");
			printf("***ERROR FOUND***.\n");
			printf("***ERROR FOUND***.\n\n");
		} 
	}
	printf("conversion is correct.\n\n");
}
#endif

#if ISPRIME
int checkPrime(unsigned int x) {
	unsigned int y, i;

	if(x==0 || x==1) {
		return 0;
	}

	if(x==2) {
		return 1;
	}

	if((x & 0x01) == 0) {
		return 0;
	}

	y = (unsigned)(sqrt((double)x));
	for (i = 3; i <= y; i+=2){
		if(x % i == 0) {
			return 0;
		}
	}
	
	return 1;
}
#endif
