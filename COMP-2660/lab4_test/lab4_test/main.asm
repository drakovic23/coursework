TITLE

; Name: Deni Rakovic
; Date: 10/17/2023
; ID: 
; Description: Lab 4 Solution

INCLUDE Irvine32.inc
INCLUDELIB Irvine32.lib

.data
val1 BYTE 10h
val2 WORD 8000h
val3 DWORD 0FFFFh
val4 WORD 7FFFh

.code
main PROC

	mov ax,7FF0h
	add al,10h ;
	;a. CF = 1 SF = 0 ZF = 1 OF = 0
	add ah,1 ;
	;b. CF = 0 SF = 1 ZF = 0 OF = 1
	add ax,2 ;
	;c. CF = 0 SF = 1 ZF = 0 OF = 0
	Call DumpRegs


	
	exit

main ENDP
END main