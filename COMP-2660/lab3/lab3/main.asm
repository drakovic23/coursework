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
	
	
.code
main PROC

	Call DumpRegs

	exit

main ENDP
END main