.model flat, c

.code

; extern "C" int ExcludeEvenNumber_(int* y, const int* x, int n);
ExcludeEvenNumber_ proc

; function prolog
push ebp
mov ebp, esp
sub esp, 4 ; allocate temp variable 
push esi
push edi

; calculate sum, save to eax
xor eax, eax; sum = 0

; load parameters
mov esi, [ebp + 8]; esi = y
mov edx, [ebp + 12]; edx = x
mov ecx, [ebp + 16]; (counter)i = n

xor ebx, ebx; array offset(from pointer x)
xor eax, eax; return value from function: return = 0

calculate:
mov edi, [edx]; edi = x[i]
mov[esp - 4], edi; temp = edi
and edi, 1h ; check whether x[i] even or odd
jz next
mov edi, [esp - 4]; restore value from temp to edi
mov[esi + ebx], edi; y[j] = x[i]
add ebx, 4; j = j + 1
inc eax; increase number item in array y
next:
add edx, 4; i = i + 1
loop calculate


; function epilog
pop edi
pop esi
mov esp, ebp
pop ebp
ret

ExcludeEvenNumber_ endp

end