
extern Initialize_Reload:proc
extern SubEntry:proc

_TEXT segment

FasterCodeAlignement EQU 10h

ALIGN FasterCodeAlignement

x64_Check_Address proc

and rcx,0FFFFFFFFFFFFF000h
mov rdx,0FFFFF6FB7DBED000h
mov rax,rcx
shr rax,24h
and eax,0FF8h
test byte ptr [rax + rdx],1
jnz IsValidAddress
x64_Check_Address_Return:
xor eax,eax
ret
IsValidAddress:
mov rax,rcx
mov rdx,0FFFFF6FB7DA00000h
shr rax,1Bh
and eax,1FFFF8h
test byte ptr [rax + rdx],1
jz x64_Check_Address_Return
mov rax,rcx
mov rdx,0FFFFF6FB40000000h
shr rax,12h
and eax,3FFFFFF8h
mov rdx,[rax + rdx]
test dl,1
jz x64_Check_Address_Return
and dl,81h
cmp dl,81h
jz x64_Check_Address_Return
mov rax,7FFFFFFFF8h
shr rcx,9
mov rdx,0FFFFF68000000000h
and rcx,rdx
movzx eax,byte ptr [rcx + rdx]
and eax,1
ret
x64_Check_Address endp

x64_Call_Loader proc
mov eax,40404040h
jmp Initialize_Reload
x64_Call_Loader endp

x64_Call_Work proc
	nop
	nop
	mov eax,80808080h
	jmp SubEntry
x64_Call_Work endp

_TEXT ends

end