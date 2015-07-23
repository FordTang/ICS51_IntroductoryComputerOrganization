#include<malloc.h>
#include<cstdio>
#include<cstring>

//when you want to test one of the parts of the assignment, just change the 0 into a 1 for
//the constant corresponding to that part
#define COUNT_ONES 1
#define FACTORIAL 1
#define POSITIVE_SUM 1
#define ISPALINDROME 0

extern char *yourName;
extern char *studentID;

struct Node{
	int e;
	struct Node *next;
};

extern unsigned int countOnes(unsigned int x);
extern int factWrapper(int i);
extern int positiveSum(struct Node *head);
extern int isPalindrome(unsigned int x);

void testOnes(unsigned int x);
void testFactorial(int x);
void testPositiveSum(int *Arr, int len);
struct Node * createList(int * Arr, int len);
void testPalindrome(unsigned int x);
void printName() {
	int nameLen = strlen(yourName) + 6;
	int idLen = strlen(studentID) + 5;
	int width;
	if (nameLen >= idLen)
		width = nameLen;
	else
		width = idLen;
	printf("+");
	for(int i = 0; i < width; i++)
		printf("-");
	printf("+\n");

	printf("|Name: %s", yourName);
	for(int i = 0; i < (width - nameLen); i++)
		printf(" ");
	printf("|\n");

	printf("+");
	for(int i = 0; i < width; i++)
		printf("-");
	printf("+\n");

	printf("|ID#: %s", studentID);
	for(int i = 0; i < (width - idLen); i++)
		printf(" ");
	printf("|\n");

	printf("+");
	for(int i = 0; i < width; i++)
		printf("-");
	printf("+\n\n");

	printf("If you don't see anything, then remember to turn on the \"#define\" flags\nin the beginning of the lab2-test.cpp file.\n");
}

void main() {
	int i;
	printName();

#if COUNT_ONES
	unsigned int test1[10] = {0, 1, 2, 3, 4, 5, 0x11111111, 0x55555555, 0xAAAAAAAA, 0xFFFFFFFF};
	for (i = 0; i < 10; i++) {
		testOnes(test1[i]);
	}
#endif

#if FACTORIAL
	for (i = 0; i <= 10; i++) {
		testFactorial(i);
	}
#endif

#if POSITIVE_SUM
	int Arr[5];

	Arr[0] = 0;
	testPositiveSum(Arr, 1);

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
#endif

#if ISPALINDROME
	unsigned int test4[10] = {0, 1, 2, 3, 5, 7, 0xA5, 0xAA55, 0xAAAA, 0xFFFFFFFF};
	for (i = 0; i < 10; i++) {
		testPalindrome(test4[i]);
	}
#endif
}

#if COUNT_ONES
void testOnes(unsigned int x) {
	unsigned count = 0;
	unsigned mask = 0x80000000;
	unsigned result;

	while (mask > x) {
		mask >>= 1;
	}
	printf("Testing countOnes...\nx=");
	while (mask) {
		if (x & mask) {
			count++;
			printf("1");
		} else {
			printf("0");
		}
		mask >>= 1;
	}

	if (x==0)
		printf("0");
	printf(". It has %u '1's.\n", count);

	result = countOnes(x);

	if (result == count)
		printf("Your result is correct.\n\n");
	else
		printf(">>>ERROR<<< Unfortunatly, your result is %u, which is incorrect.\n\n", result);
}
#endif

#if FACTORIAL
void testFactorial(int x) {
	int result;
	int correct = 1;

	for (int i = 1; i <= x; i++) {
		correct *= i;
	}

	printf("Testing factorial of %d...\nThe correct answer is %d.\n", x, correct);

	result = factWrapper(x);

	if (result == correct)
		printf("Your result is correct.\n\n");
	else
		printf(">>>ERROR<<< Unfortunately, your result is %d, which is incorrect.\n\n", result);

}
#endif

#if POSITIVE_SUM
struct Node * createList(int * Arr, int len) {
	if (len == 0) {
		return NULL;
	}

	struct Node *head = (struct Node*)malloc(sizeof(struct Node));
	head->e = Arr[0];

	struct Node *tail = head;

	for (int i = 1; i < len; i++) {
		struct Node *next = (struct Node*)malloc(sizeof(struct Node));
		tail->next = next;
		tail = next;
		tail->e = Arr[i];
	}
	tail->next = NULL;

	return head;
}

void testPositiveSum(int *Arr, int len) {
	struct Node *head = createList(Arr, len);
	int correct, result;
	struct Node *p = head;
	correct = 0;

	printf("Testing positiveSum...\nThe list contains ");
	while(p) {
		printf("%d, ", p->e);
		if (p->e > 0) {
			correct += p->e;
		}
		p = p->next;
	}
	printf("and the positive sum is %d.\n", correct);

	result = positiveSum(head);

	if (result == correct)
		printf("Your result is correct.\n\n");
	else
		printf(">>>ERROR<<< Unfortunately, your result is %d, which is incorrect.\n\n", result);

}
#endif

#if ISPALINDROME
void testPalindrome(unsigned int x) {
	unsigned left=0x80000000, right=1;
	int correct, result;

	while(left > x)
		left >>= 1;

	printf("Testing isPalindrome...\nx=");
	for(unsigned mask = left; mask; mask >>= 1) {
		if (x & mask)
			printf("1");
		else
			printf("0");
	}
	if (x==0)
		printf("0");
	printf(", ");

	while (left > right) {
		if (x & left) {
			if ((x & right) == 0) {
				break;
			}
		} else {
			if (x & right) {
				break;
			}
		}
		left >>= 1;
		right <<= 1;
	}

	if( left > right ) {
		printf("and it is not a palindrome.\n");
		correct = 0;
	} else {
		printf("and it is a palindrome.\n");
		correct = 1;
	}

	result = isPalindrome(x);

	if (result == correct)
		printf("Your result is correct.\n\n");
	else
		printf(">>>ERROR<<< Unfortunatly, your result is incorrect.\n\n");

}
#endif