section .data
    num_255 dq 255.0
    
section .text
    default rel

global imgCvtGrayDoubleToInt
imgCvtGrayDoubleToInt:
    PUSH RBP
    MOV RBP, RSP
    
    ; xmm0 stores 255.0
    MOVSD xmm0, [num_255]
    
CONTINUE:
    ; Finish function if all elements have been iterated through
    TEST R8, R8
    JZ FINISH
    
    ; xmm1 stores current float
    MOVSD xmm1, [RCX]
    
    ; Multiply xmm1 (current float) to xmm0 (255.0)
    MULSD xmm1, xmm0
    
    ; Convert xmm1 to integer and store in EAX
    CVTSD2SI EAX, xmm1 

    ; Store xmm1 (converted integer) to output array
    MOV [RDX], EAX
    
    ; Move to next double in the input array
    ADD RCX, 8
    
    ; Move to next integer in the output array
    ADD RDX, 4
    
    ; Decrement R8 (matrix size)
    DEC R8
    
    JMP CONTINUE

FINISH:
    POP RBP
    RET