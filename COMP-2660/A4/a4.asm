TITLE

; Name: Deni Rakovic
; Date: 11/20/2023
; ID: 110081508
; Description: A4 Section 2 Solution

INCLUDE Irvine32.inc
INCLUDELIB Irvine32.lib

; these two lines are only necessary if you're not using Visual Studio
INCLUDELIB kernel32.lib
INCLUDELIB user32.lib

.data
    
	; data declarations go here
	key BYTE 2, 4, -1, 0, 3, 5, 2, 4, 4, 6
	text BYTE "This is a secret message", 0
	len DWORD ?

.code
main PROC

    lea esi, text
    mov ecx, LENGTHOF text - 1
    ;mov len, ecx
    mov ebx, 0

    ; loop through each char
    l_start:
        cmp ecx, 0
        jle l_end

        mov al, [esi] 
        movzx edx, byte ptr key[ebx] ;key val
        call RotateByte
        mov [esi], al

        inc esi ;go to next char
        inc ebx ;next key
        cmp ebx, 10 ;if ebx = 10 reset the key index
        jl short next_char 
        mov ebx, 0
        next_char:
        dec ecx
        jmp l_start
    l_end:

    mov edx, OFFSET text
    call WriteString
    call Crlf

	exit

main ENDP

RotateByte PROC
    cmp edx, 0
    jge rotate_right
    neg edx
    rotate_left:
        rol al, 1
        dec edx
        jnz rotate_left
    jmp rotate_done
    rotate_right:
        ror al, 1         
        dec edx
        jnz rotate_right
    rotate_done:
    ret
RotateByte ENDP
END main
