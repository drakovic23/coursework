TITLE

; Name: Deni Rakovic
; Date: 10/17/2023
; ID: 110081508
; Description: Lab 4 Solution Section 53

INCLUDE Irvine32.inc
INCLUDELIB Irvine32.lib


.data
	myBytesLabel LABEL WORD ;Allows moving myBytes to a 16 bit register (Question 2.5)
	myBytes BYTE 10h,20h,30h,40h
	myWordsLabel LABEL DWORD; this label allows moving my myWords to 32 bit register (Question (2.4))
	myWords WORD 3 DUP(?),2000h
	myString BYTE "ABCDE"

.code
main PROC

	mov dx, WORD PTR[myBytes] ;Move first two bytes (Question 2.1)
	mov al, BYTE PTR[myWords + 1] ;Move second byte in myWords (Question 2.2)
	mov eax, DWORD PTR [myBytes] ;Move all four bytes (Question 2.3)
	
	
	;Question (2.6)
	mov eax, TYPE myBytes; EAX is 1 as TYPE myBytes is byte so eax = 1
	mov eax, LENGTHOF myBytes; myBytes has 4 elements so length of myBytes is 4, eax = 4
	mov eax, SIZEOF myBytes; myBytes has 4 elements each of size 1 byte so eax = 4
	mov eax, TYPE myWords; myWords is of type WORD so TYPE returns 2 bytes, eax = 2
	mov eax, LENGTHOF myWords; myWords has 4 elements in the array, eax = 4
	mov eax, SIZEOF myWords; myWords has 4 elements of 2 bytes each so 4 * 2 = 8, eax = 8
	mov eax, SIZEOF myString; myString contains 5 char, so eax = 5

	exit

main ENDP
END main