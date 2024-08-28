TITLE

; Name: Deni Rakovic
; Date: 10/3/2023
; ID: 110081508
; Description: Lab 3 Solution Section 53

INCLUDE Irvine32.inc
INCLUDELIB Irvine32.lib

.data

	val1 BYTE 10h
	val2 WORD 8000h
	val3 DWORD 0FFFFh
	val4 WORD 7FFFh
	val5 DWORD ?
	arrayW WORD 100h,200h,300h
	byte 20 DUP(0)

.code
main PROC

	INC val2 ; (1) - Increment val2

	SUB eax, val3 ; (2)- Subtract val 3 from eax
	;Call DumpRegs

	;(3) - Subtract val4 from val2
	MOV ax, val2
	SUB ax, val4
	MOV val2, ax ;Store value in val2

	;(4) - val5 = -val1 - (val2 + val4)
	MOVSX eax, val1 ;eax = val1
	NEG val1 ;eax = -val1
	MOVZX ebx, val2 
	MOVZX ecx, val4 ;ebx = val2 and ecx= val4
	ADD ebx, ecx ;ebx now = val2 + val4
	;Call DumpRegs
	SUB eax, ebx
	MOV val5, eax

	;(5) If val2 is 
	;incremented by 1 CF = 0, SF = 0
	ADD val2, 1
	Call DumpRegs
	;(6) - If val4 is decremented by 1 OF = 0, SF = 0
	SUB val4, 1
	Call DumpRegs

	;(7) - Add the last element of the array to val4
	MOV ax, val4
	ADD ax, [arrayW + 4] ;Increment by 2 bytes so last element is 4
	MOV val4, ax ;Store value

	;(8) - Write down values of Carry, Sign, Zero and OF flags
	mov val2,7FF0h
	add val2,10h ; a. CF = 0 SF = 1 ZF = 0 OF = 1
	;Call DumpRegs
	add val2,1 ; b. CF = 0 SF = 1 ZF = 0 OF = 0
	;Call DumpRegs
	add val2,2 ; c. CF = 0 SF = 1 ZF = 0 OF = 0
	;Call DumpRegs

	;(9)EAX = 00030000h
	;The purpose of the code segment is to add val 1 to val 2 via EAX register
	;and then subtract val3 from the result. Finally the value is stored in finalVal variable by moving EAX into finalVal	


	exit

main ENDP
END main