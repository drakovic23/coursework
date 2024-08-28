TITLE

; Name: Deni Rakovic
; Date: 9/26/2023
; ID: 110081508
; Description: Lab 2

INCLUDE Irvine32.inc
INCLUDELIB Irvine32.lib

.data

	Rval SDWORD 22
	Xval SDWORD 26
	Yval SDWORD 30
	Zval SDWORD 40

.code
main PROC
	
	;Part (A) - CF, SF, ZF and OF are not activated (0)
	;	      - AL: 00h
	;			CX: 2182h
	
	mov ax,1000h
	inc ax
	dec ax
	mov eax,Xval
	neg eax
	mov ebx,Yval
	sub ebx,Zval
	add eax,ebx
	mov Rval,eax
	mov cx,1
	sub cx,1
	mov ax,0FFFFh
	inc ax
	mov ecx,0B9F6h
	sub ecx,9874h
	call DumpRegs

	;Part(B) - CF = 0, SF = 1, ZF = 0, OF = 1
	;SF is activated because the result is negative because EAX is negative
	;OF flag is activated because there is a overflow in addition of AX (adding 7FFFh and 2)
	;Value of AL is 01h
	;Value of CX is FFFFh

	mov cx,0 
	sub cx,1
	mov ax,7FFFh
	add ax,2
	call DumpRegs

	;Part(C) - CF = 0, SF = 1, ZF = 0, OF = 1
	;Value of AL is 20h
	;Value of CX is FFFF
	;SF flag is activated because AX is negative because all three addition operations end up with negative numbers (al, al, ax additions)
	;OF flag is activated because overlfow in AL and AX addition
	;For AL adding FFh and 1 cause overflow
	;For AL again adding 7F and 1 causes overflow
	;For AX adding 7FFEh and 22 cause overflow
	mov al,0FFh 
	add al,1
	mov al,+127
	add al,1
	mov ax,7FFEh
	add ax,22h
	call DumpRegs

	;Part(D) - ERROR RUNNING CODE

	exit

main ENDP
END main