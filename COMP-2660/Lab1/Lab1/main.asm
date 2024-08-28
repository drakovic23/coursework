TITLE

; Name: Lab 1 Part 1
; Date: 9/18/2023
; ID: 
; Description: Lab 1 part 1 solution

INCLUDE Irvine32.inc
INCLUDELIB Irvine32.lib

.data

	; data declarations
	Var1 DWORD 10000h
	Var2 DWORD 20000h

	Var3 DWORD 30000h
	Var4 DWORD 10000h

	testVar DWORD 30000d ; For testing
	testVar2 DWORD 10000d

.code
main PROC

	
	MOV eax, var1
	ADD eax, var2
	call DumpRegs ; EAX should be 30000d
	;call WriteHex ;PF = 1
	
	;part two
	MOV eax, Var3
	SUB	eax, Var4
	call DumpRegs ;EAX should be 20000d
	;call WriteHex ;PF = 1

	;Testing decimal type
	MOV eax, testVar
	SUB eax, testVar2
	call DumpRegs ; When calling this the EAX shows in hexadecimal instead
	;call WriteBin ; PF = 0

	exit

main ENDP
END main