TITLE

; Name:
; Date:
; ID: 
; Description: 

INCLUDE Irvine32.inc
INCLUDELIB Irvine32.lib

.data

	myBytes BYTE 10h,20h,30h,40h
	myWords WORD 3 DUP(?),2000h
	myString BYTE ”ABCDE”

.code
main PROC

	; program syntax here
	mov dx, WORD PTR [myBytes]
	call DumpRegs ; displays registers in console

	exit

main ENDP
END main