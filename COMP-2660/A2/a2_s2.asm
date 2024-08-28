TITLE

; Name: Deni Rakovic
; Date: 10/24/2023
; ID: 110081508
; Description: Assignment 2 Section 2 Solution

INCLUDE Irvine32.inc
INCLUDELIB Irvine32.lib

; these two lines are only necessary if you're not using Visual Studio
INCLUDELIB kernel32.lib
INCLUDELIB user32.lib

.data

    ;Queston A - fib
    fibVals   DWORD 7 dup(0)     ; fib array
    counter   DWORD 5            ; counter
    prev1     DWORD 1            ; prev num
    prev2     DWORD 1            ; 2nd prev num
    index     DWORD 2            ; index

    ;Question B
    
    byteVal      BYTE    250           
    sbyteVal     SBYTE   -64           
    wordVal      WORD    300         
    swordVal     SWORD   -32700          
    dwordVal     DWORD   4000000     
    sdwordVal    SDWORD  -2000000   
    qwordVal     QWORD   1000000000
	
    ;Question C
    dwordArray DWORD 10000h, 20000h, 30000h, 40000h
    sum DWORD 0;

.code
main PROC
	
    ;Question A

    ; first two fib nums
    mov eax, prev2             
    mov [fibVals], eax         
    mov eax, prev1             
    mov [fibVals + 4], eax     

    ; Begin the loop
Lfib::
    mov eax, prev1
    add eax, prev2

    ; store fib(n) into array
    mov edx, index
    shl edx, 2                
    add edx, offset fibVals
    mov [edx], eax

    ; Update prev numbers
    mov edx, prev1            
    mov prev1, eax            
    mov prev2, edx            

    inc index
    dec counter

    cmp counter, 0
    jne LFib

end_loop:
    mov ecx, 7
    mov edx, offset fibVals

print_loop: ;print fib nums
    mov eax, [edx]            
    call WriteInt             
    add edx, 4                
    loop print_loop           
    call Crlf

    ;Question C
    mov esi, offset dwordArray 
    mov ecx, LENGTHOF dwordArray             

LSum:
    mov eax, [esi]          
    add sum, eax    ; add val to sum
    add esi, 4      ; go next
    loop LSum   ; repeat

    mov eax, sum ;move sum to eax and print
    call WriteHex
    call Crlf

    Call DumpRegs

    exit

main ENDP
END main
