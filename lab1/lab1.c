//ICS 51. Lab #1

#include <stdio.h>

char * yourName = "Ford Tang";
char * studentID = "46564602";
/*******************************************************************************
    Part A.
	Inplement positiveSum function that calculates the sum of all the positive
	numbers in an integer array. The signature of positiveSum function is:

    int positiveSum( int *Arr, int len );

	It has 2 arguments. int *Arr is a pointer, which points to the beginning of
	the array. int length is the length of the array. To return the result, you
	should store it in register EAX. Since all the registers are visible by the
	caller function, when we want to return something, we can just leave it in a
	register. The convetnion is to leave the return value in EAX.

	In an array, several integers are stored together, one after another.
	So if the first element in the array is at the address of 3064, the next
	element will be at 3068, and the next will be 3072. This is because each
	integer occupies 4 bytes of memory. 

	Example:
	If we have an array of [1, 3, -5, 7], the sum should be 1 + 3 + 7 = 11.
*******************************************************************************/

int positiveSum( int *Arr, int len ) {
	__asm{
		PUSH EBX
		PUSH ECX
		PUSH EDX
		PUSH ESI
		PUSH EDI

		MOV EBX, Arr
		MOV ECX, len

		/* Your code begins below this line. */
		MOV EAX, 0				//Clearing EAX so return is ready.
		MOV EDX, 0				//Moving zero ito EDX, Using EDX as counter and current index of array.

CHECK:
		CMP EDX, ECX			//Comparing current index of array to the total length of array.
		JG END					//If current index is greater than total length of array, jump to END.
		CMP [EBX+EDX*4], 0		//Comparing value in current index against zero.
		JL SKIP					//If current index value is less than zero, jump to SKIP.
		ADD EAX, [EBX+EDX*4]	//Add current index value to EAX(return register).

SKIP:
		ADD EDX, 1				//Add 1 to EDX(current index of array counter)
		JMP CHECK				//Jump to CHECK to continue the loop.

END:		
		/* Your code ends above this line. */

		POP EDI
		POP ESI
		POP EDX
		POP ECX
		POP EBX
	}
}



/*******************************************************************************
	Part B.
	Implement the toUpper function that converts lower-case letters in a string
	to upper-case. The function takes one parameter: char *string. string is a
	char type pointer, which points to the beginning of the string. Because C-
	style strings are terminated by a zero, we do not need to take the length of
	the string as another parameter. Please see hint 2 for more details.

	You should do the conversion in-place, which means you should change the
	characters in its original location.

	A few hints:
	1. Only lower-case letters are converted. Punctuation marks should remain
	the same.

	2. Here is how strings are stored in the memory:
    A string is an array of ASCII characters. So the string is actually an array
	of ASCII values. In C/C++, we use a char type pointer (char*) to denote the
	beginning of a string. The pointer points to the very first character of the
	string. How do we find the end? The end of a string represented by a 0. For
	example, "Hello" is stored as 72, 101, 108, 108, 111, 0. Zero (0) could be
	used as the terminating symbol, because all valid ASCII characters are non-
	zero. Note that "Hello" is actually 5 characters long, but it requires 6
	bytes of storage, including the terminating 0.

    3. Changing a character is actually adjusting its ASCII value. Use Google
	to find an ASCII table and observe, what change is required to switch
	between upper and lower case.

*******************************************************************************/

void toUpper(char *string) {
	__asm{

		PUSH EAX
		PUSH EBX
		PUSH ECX
		PUSH EDX
		PUSH ESI
		PUSH EDI

		MOV EBX, string

		/* Your code begins below this line. */
		MOV ECX, 0				//Moving zero into ECX, using ECX as the counter for current index in array.

CHANGE:
		CMP [EBX+ECX], 0		//Comparing current index value to 0.
		JE END					//Jump if current index value is less than zero (End of string).
		CMP [EBX+ECX], 97		//Comparing current index value to the starting value of the lower-case alphabets in the ASCII table.
		JL SKIPCHAR				//If current index value(character) is less than starting value for lower-case alphabets in ASCII table, jump to SKIPCHAR.
		CMP [EBX+ECX], 122		//Comparing current index value to the last value of the lower-case alphabets in the ASCII table.
		JG SKIPCHAR				//If current index value(character) is greater than the last value for lower-case alphabets in the ASCII table, jump to SKIPCHAR.
		AND [EBX+ECX], 223		//AND current index value(character) to 11011111(binary), which will change lowercase letters to uppercase, will not change uppercase letters.

SKIPCHAR:
		ADD ECX, 1				//Add 1 to ECX(counter for current array index)
		JMP CHANGE				//Jump to CHANGE to continue loop.

END:
		/* Your code ends above this line. */

		POP EDI
		POP ESI
		POP EDX
		POP ECX
		POP EBX
		POP EAX
		
	}
}

/*******************************************************************************
	Part C. (Optional, will not be graded)
	Inplement isPrime function that tests if an integer is a prime number.	The 
	function takes an unsigned integer as parameter, and returns 1 if the
	integer is a prime number, and 0 otherwise. For this part, you should learn
	to use the DIV instruction.

	Example: 

	isPrime(2) returns 1
	isPrime(4) returns 0.

	Hint: What happens to your algorithm if x = 0? or x = 1?

	Bonus questions: (No extra credit)
	To test if x is a prime number or not, what is the minimum number of
	divisions you'll have to calculate? How many divisions are you calculating
	in your own implementation? How to make your program run faster?
*******************************************************************************/

int isPrime(unsigned int x) {
	__asm{

		PUSH EBX
		PUSH ECX
		PUSH EDX
		PUSH ESI
		PUSH EDI

		MOV EDI, x

		/* Your code begins below this line. */
		CMP EDI, 2		//Comparing EDI with the value 2, checking to see if EDI is less than 2.
		JL NOTPRIME		//Jump if EDI is less than 2 to NOTPRIME.
		CMP EDI, 2		//Comparing EDI with the value 2, if EDI is 2, number is prime.
		JE PRIME		//Jump if EDI is equal to 2, jump to PRIME
		CMP EDI, 3		//Comparing EDI with the value 3, if EDI is 3, number is prime.
		JE PRIME		//Jump if EDI is equal to 3, jump to PRIME
		MOV EAX, EDI	//Moving EDI into EAX, using EAX to check for even number.
		AND EAX, 1		//AND EAX with 1, if result is 0, number is even.
		CMP EAX, 0		//Comparing EAX with 0, if EAX is zero, the original number was even and not prime.
		JE NOTPRIME		//If EAX was zero, jump to NOTPRIME.
		MOV EBX, 3		//Move 3 into EBX, readying EBX to be the divisor of EDI

CHECKPRIME:
		MOV EDX, 0
		MOV EAX, EDI	//Moving EDI into EAX so EAX can be divided by EBX
		DIV EBX			//Divide EAX by EBX, the remainder goes to EDX
		CMP EDX, 0		//Comparing EDX to zero, if value is zero, the number divided successfully and is not prime.
		JE NOTPRIME		//If EDX(remainder) is zero, number was divided successfully and the number is not prime.  Jump to NOTPRIME.
		ADD EBX, 2		//ADD 2 to EBX(new divisor value)
		MOV EAX, EBX	//Move EBX into EAX, checking to see if divisor is less than the square root of the given number.
		MUL EAX			//Multiplying EAX(divisor) by itself to see if is less than the given number.
		CMP EAX, EDI	//Comparing EAX with EDI(given number).
		JG PRIME		//If EAX is greater than the given number, than no number has been divided successfully into the given number, and the number is prime.  Jump to PRIME.
		JMP CHECKPRIME	//Jump back to CHECKPRIME to continue checking the given number.
		
NOTPRIME:
		MOV EAX, 0		//Move zero into EAX, returning False for result.
		JMP END			//Jump to END

PRIME:
		MOV EAX, 1		//Move 1 into EAX, returning True for result.

END:
		/* Your code ends above this line. */

		POP EDI
		POP ESI
		POP EDX
		POP ECX
		POP EBX
	}
}

