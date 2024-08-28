TITLE

; Name: Deni Rakovic
; Date: 10/17/2023
; ID: 
; Description: Lab 4 Solution

INCLUDE Irvine32.inc
INCLUDELIB Irvine32.lib

.data

	array DWORD 20h,30h,50h,40h,20h,60h
	sum DWORD ?

.code
main PROC
	;Sum of an array (Question 3.1)
	mov ecx, LENGTHOF array
	mov ax, 0
	mov esi, 0

L1: add eax, array[esi * TYPE array]
	inc esi
	loop L1

	mov sum, eax

	Call DumpRegs



	;(Question 3.2 - written in C)
	;	#include <stdio.h>

	;int main()
	;{

	;	int arr[5] = {5,10,15,20,25};
	;	int sum = 0;
	;
	;	for(int x = 0; x < 5; x++)
	;	{
	;		sum += arr[x];
	;	}
	;
	;	printf("%d", sum);
	;
	;	return 0;
;	}
	
	;(Question 3.3)
	;Three main differences - Can declare an array and memory is managed for us in C or Java
	;                       - Error handling is better in C/Java, debugging is different in AL
	;						- Higher level of abstraction in C/Java


	;(Question 3.4)
	; SPeed of using a register is quicker
	; Holding an array element in reference in a register, CPU can access more quickl
	; An alternative is direct memory addressing
	exit

main ENDP
END main