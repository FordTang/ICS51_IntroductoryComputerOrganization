#include <stdio.h>
#include <ctype.h>

/*
  You are given three integer numbers. You need to add the smallest number to
  the largest number and multiply the resulting sum by two.

  Implementation details:
The three integer numbers are stored in registers eax, ebx, and ecx. You need 
to store the answer into register edx.

IMPORTANT comments:
(i)   To test your code see the "testcode" function in lab0-testing.c
(ii)  Write your assembly code only in the marked block.
(iii) DO NOT write any code outside the marked block.
(iv)  You are not allowed to use any version of the MULTIPLY instruction!
*/

char *yourName = "Ford Tang";
char *yourStudentID   = "46564602";

/* You are supposed to implement the body of this function */

void lab0( int a, int b, int c, int *result )
{
	__asm 
	{
		mov esi, result
		push eax
		push ebx
		push ecx
		push edx

		mov eax, a
		mov ebx, b
		mov ecx, c

// YOUR CODE STARTS HERE

/*
To sort 3 numbers, we use the following algorithm:
if a < b:
	swap a, b	
if a < c:
	swap a, c
if b < c
	swap b, c
*/
		cmp eax, ebx	// if eax < ebx
		jge L1
		mov edx, eax	// swap eax, ebx
		mov eax, ebx
		mov ebx, edx
L1:
		cmp eax, ecx	// if eax < ecx
		jge L2
		mov edx, eax	// swap eax, ecx
		mov eax, ecx
		mov ecx, edx
L2:
		cmp ebx, ecx	// if ebx < ecx
		jge L3
		mov edx, ebx	// swap ebx, ecx
		mov ebx, ecx
		mov ecx, edx
L3:
		add eax, ecx
		sal eax, 1		// eax = eax * 2
		mov edx, eax

// YOUR CODE ENDS HERE

END:
		mov [esi][0], edx
		pop edx
		pop ecx
		pop ebx
		pop eax
	}
	return;

}
