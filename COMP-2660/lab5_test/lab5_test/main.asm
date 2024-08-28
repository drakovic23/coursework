TITLE

; Name:
; Date:
; ID: 
; Description: 

INCLUDE Irvine32.inc
INCLUDELIB Irvine32.lib

.data

	source BYTE "HELLO.", 0

.code
main PROC

	; program syntax here
	mov ecx, LENGTHOF source - 1 ;length of source string minus null terminator (counter)
	mov esi, OFFSET source ;esi points to beginning of string
	mov eax, 0 ;clear eax
L1: mov al, BYTE PTR[esi] ;get a single byte from memory instead of 32 bits
	push eax
	inc esi
	loop L1

	;Pop the values and reverse
	mov ecx, LENGTHOF source-1
	mov esi, OFFSET source

L2: pop eax ;stack contains char so we pop
	mov [esi], al
	inc esi
	loop L2

	call DumpRegs ; displays registers in console

	exit

main ENDP
END main