long arith2(long x, long y, long z) {
    long t1 = x | y;
    long t2 = t1 >> 3;
    long t3 = ~t2;
    long t4 = z - t3;
    return t4;
}


/*
arith2:
    orq	    %rsi, %rdi
    sarq    $3, %rdi
    notq    %rdi
    movq    %rdx, %rax
    subq    %rdi, %rax
    ret
*/
