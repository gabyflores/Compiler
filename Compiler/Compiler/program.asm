section .data
msg10 db 0xA,0xD,"----------Operaciones---------------"
len10 equ $ - msg10
msg11 db 0xA,0xD,"La multiplicacion 2*3:"
len11 equ $ - msg11
msg12 db 0xA,0xD,"La division de 6/2 es:"
len12 equ $ - msg12
msg13 db 0xA,0xD,"--------Lee Datos-------------------"
len13 equ $ - msg13
msg14 db 0xA,0xD,"Ingrese un numero:"
len14 equ $ - msg14
msg15 db 0xA,0xD,"Numero ingresado:"
len15 equ $ - msg15
msg16 db 0xA,0xD,"Ingrese una letra:"
len16 equ $ - msg16
msg17 db 0xA,0xD,"Letra Ingresada:"
len17 equ $ - msg17
msg18 db 0xA,0xD,"----Operaciones Dos-----"
len18 equ $ - msg18
msg19 db 0xA,0xD,"La resta es:"
len19 equ $ - msg19
msg110 db 0xA,0xD,"La suma es:"
len110 equ $ - msg110
section .bss
res resb 1
section .text
global _start
_start:
;-----------imprime mensajes
mov eax,4
mov ebx,1
mov ecx, msg10
mov edx, len10
int 0x80
mov eax,2 
mov ebx,3 
mul ebx
add eax,'0'
mov [res],eax
;-----------imprime mensajes
mov eax,4
mov ebx,1
mov ecx, msg11
mov edx, len11
int 0x80
mov eax,4
mov ebx,1
mov ecx, res
mov edx, 1
int 0x80
mov eax,6 
mov ebx,2 
mov edx,0
div ebx
add eax,'0'
mov [res],eax
;-----------imprime mensajes
mov eax,4
mov ebx,1
mov ecx, msg12
mov edx, len12
int 0x80
mov eax,4
mov ebx,1
mov ecx, res
mov edx, 1
int 0x80
;-----------imprime mensajes
mov eax,4
mov ebx,1
mov ecx, msg13
mov edx, len13
int 0x80
;-----------imprime mensajes
mov eax,4
mov ebx,1
mov ecx, msg14
mov edx, len14
int 0x80
mov eax,3
mov ebx,2;leer
mov ecx,res
mov edx,5;lecturas
int 0x80
;-----------imprime mensajes
mov eax,4
mov ebx,1
mov ecx, msg15
mov edx, len15
int 0x80
mov eax,4
mov ebx,1
mov ecx, res
mov edx, 1
int 0x80
;-----------imprime mensajes
mov eax,4
mov ebx,1
mov ecx, msg16
mov edx, len16
int 0x80
mov eax,3
mov ebx,2;leer
mov ecx,res
mov edx,5;lecturas
int 0x80
;-----------imprime mensajes
mov eax,4
mov ebx,1
mov ecx, msg17
mov edx, len17
int 0x80
mov eax,4
mov ebx,1
mov ecx, res
mov edx, 1
int 0x80
;-----------imprime mensajes
mov eax,4
mov ebx,1
mov ecx, msg18
mov edx, len18
int 0x80
mov eax,4 
mov ebx,2 
sub eax,ebx
add eax,'0'
mov [res],eax
;-----------imprime mensajes
mov eax,4
mov ebx,1
mov ecx, msg19
mov edx, len19
int 0x80
mov eax,4
mov ebx,1
mov ecx, res
mov edx, 1
int 0x80
mov eax,2 
mov ebx,2 
add eax,ebx
add eax,'0'
mov [res],eax
;-----------imprime mensajes
mov eax,4
mov ebx,1
mov ecx, msg110
mov edx, len110
int 0x80
mov eax,4
mov ebx,1
mov ecx, res
mov edx, 1
int 0x80
mov eax,1;system pause
int 0x80
