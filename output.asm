extern printf
global main
print:
	push ebp
	mov ebp, esp
	push edx
	push ecx
	push ebx
	push eax
	push format
	call printf  ; printf(format, 2)
	pop eax
	pop eax
	pop ebx
	pop ecx
	pop edx
	mov esp, ebp
	pop ebp
	ret
main:
	push ebp
	mov ebp,esp
	sub esp,0x20
	mov dword [ebp-4],2
	mov dword [ebp-8],30
	mov dword [ebp-12],10
	mov edx,dword [ebp-12]
	mov dword [ebp-12],edx
	mov edx,dword [ebp-12]
	mov dword [ebp-12],edx
	mov eax,dword [ebp-12]
	imul eax,dword [ebp-4]
	mov edx,eax
	sub 
	mov dword [ebp-12],edx
	mov eax,dword [ebp-12]
	mov ebx,dword [ebp-4]
	push edx
	cdq
	idiv ebx
	pop edx
	mov edx,eax
	sub 
	mov dword [ebp-12],edx
	mov eax,dword [ebp-12]
	add eax,dword [ebp-4]
	mov edx,eax
	sub 
	mov dword [ebp-12],edx
	mov eax,dword [ebp-12]
	sub eax,dword [ebp-4]
	mov edx,eax
	sub 
	mov dword [ebp-12],edx
	mov eax,dword [ebp-12]
	imul eax,dword [ebp-4]
	mov edx,eax
	sub 
	mov dword [ebp-12],edx
	mov eax,dword [ebp-12]
	mov ebx,dword [ebp-4]
	push edx
	cdq
	idiv ebx
	pop edx
	mov edx,eax
	sub 
	mov dword [ebp-12],edx
	mov eax,dword [ebp-4]
	add eax,dword [ebp-8]
	mov edx,eax
	imul edx,dword [ebp-12]
	mov eax,dword [ebp-8]
	mov ebx,2
	push edx
	cdq
	idiv ebx
	pop edx
	sub edx,eax
	mov eax,dword [ebp-8]
	add eax,dword [ebp-12]
	imul edx,eax
	mov dword [ebp-12],edx
	mov eax,dword [ebp-12]
	call print
	mov esp,ebp
	pop ebp
	ret
section .data
	format db 'eax:%d ebx:%d ecx:%d edx:%d  ',0    ;set the form of int
