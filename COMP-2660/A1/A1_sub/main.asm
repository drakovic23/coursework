TITLE

; Name: Assignment 1 - COMP 2660 F23
; Date: 9/22/2023
; ID: 110081508
; Description: Assignment 1 Section 2 Solution

INCLUDE Irvine32.inc
INCLUDELIB Irvine32.lib

.data

	; data declarations go here
	X DWORD ?
	Y DWORD ?

.code
main PROC
	;Part one
	MOV eax, X
	ADD eax, Y
	ADD eax, 4
	MOV ebx, 3
	MUL ebx

	call DumpRegs ; EAX = 12 or 'C'

	;Part two
	MOV eax, 20000h
	ADD eax, 30000h
	SUB eax, 10000h

	call DumpRegs

	exit

main ENDP
END main