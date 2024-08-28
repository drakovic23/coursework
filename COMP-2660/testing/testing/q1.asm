TITLE

; Name: Deni Rakovic
; Date: 10/24/2023
; ID: 110081508
; Description: Lab 5 Question 1

INCLUDE Irvine32.inc
INCLUDELIB Irvine32.lib
TAB = 9 ; ASCII code for Tab

.data

	; data declarations go here
	text BYTE "hello", 0

.code
main PROC
    Call Randomize ;So we get uniques each time
    mov ecx, 50  ; loop 50 times
L1:
    mov ebx, -300 ; lower bound
    mov eax, 100  ; upper bound
    call BetterRandomRange
    call WriteInt ; write num
    mov al, TAB   ; 
    call WriteChar; tab
    loop L1       ; loop
    call Crlf     ; newl
    exit
main ENDP

 BetterRandomRange PROC
    ; Output: EAX contains random integer between M and N-1
    sub eax, ebx     ; Get the range (N-M)
    call RandomRange ; Generate a random number between 0 and eax-1
    add eax, ebx     ; Adjust to get a number between M and N-1
    ret
BetterRandomRange ENDP
END main