TITLE

; Name: Deni Rakovic
; Date: 10/17/2023
; ID: 110081508
; Description: Lab 4 Solution Section 53

INCLUDE Irvine32.inc
INCLUDELIB Irvine32.lib

; Create user-defined types
PBYTE TYPEDEF PTR BYTE ; pointer to bytes
PWORD TYPEDEF PTR WORD ; pointer to words
PDWORD TYPEDEF PTR DWORD ; pointer to doublewords

.data

	arrayB BYTE 10h, 20h, 30h
	arrayW WORD 1, 2, 3
	arrayD DWORD 4, 5, 6

	; Create some pointer variables.
	ptr1 PBYTE arrayB ; Pointers point to beginning of each array
	ptr2 PWORD arrayW
	ptr3 PDWORD arrayD
.code
main PROC

	; Use the pointers to access data.
	mov esi, ptr1
	mov al, [esi] ; (a) AL contains 10h
	mov esi, ptr2
	mov ax, [esi] ; (b) AX contains 1
	mov esi, ptr3
	mov eax, [esi] ; (c) EAX contains 4


	;PART B
	mov eax,0
	mov ecx,10 ; outer loop counter
	L1:
	mov eax,3
	mov ecx,5 ; inner loop counter
	L2:
		add eax,5
	     loop L2 ; repeat inner loop
	loop L1 ; repeat outer loop

	;EAX = 28

	exit

main ENDP
END main