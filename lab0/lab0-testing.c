#include <stdio.h>
#include <ctype.h>
#include <string.h>

extern void lab0(int a, int b, int c, int *result);

extern char *yourName;
extern char *yourStudentID;
static void testcode();

int main(void)
{
	testcode();
	return 0;
}

static void testcode (void)
{
	int *result;

	printf ("ICS 51 Lab 0 \nName:      %s\nStudentID: %s\n\n", 
	  yourName, yourStudentID);

  /* Once you are done implementing the function, activate one or more of
     the following test sequences.
     Procedure to activate a single test sequence:
         replace 
              #define TEST2 0
         with
              #define TEST2 1
     You can similarly activate TEST1 and TEST3
  */

	#define TEST1 1
	#define TEST2 1
	#define TEST3 1

	#if TEST1
		result = (int*) malloc(sizeof(int));
		lab0(100,240,3,result);
		printf( "Input = %d, %d, %d, Output = %d\n", 100, 240, 3, *result );
		free(result);
	#endif

	#if TEST2
		result = (int*) malloc(sizeof(int));
		lab0(4,2,7,result);
		printf( "Input = %d, %d, %d, Output = %d\n", 4, 2, 7, *result );
		free(result);
	#endif

	#if TEST3
		result = (int*) malloc(sizeof(int));
		lab0(3,3,3,result);
		printf( "Input = %d, %d, %d, Output = %d\n", 3, 3, 3, *result );
		free(result);
	#endif

	printf( "\nHit enter to quit" );
	getchar();
}
