#include "libasm.h"

void    test_ft_strcpy() {
    char src[100] = "Hello World!";
    char dst[100] = "";
    printf("ft_strcpy(dst, \"%s\") = \"%s\"\n", src, ft_strcpy(dst, src));
    printf("strcpy(dst, \"%s\") = \"%s\"\n", src, strcpy(dst, src));
    printf("\n");

    src[0] = '\0';
    printf("ft_strcpy(dst, \"%s\") = \"%s\"\n", src, ft_strcpy(dst, src));
    printf("strcpy(dst, \"%s\") = \"%s\"\n", src, strcpy(dst, src));
    printf("\n");

    src[0] = 'H';
    src[1] = '\0';
    printf("ft_strcpy(dst, \"%s\") = \"%s\"\n", src, ft_strcpy(dst, src));
    printf("strcpy(dst, \"%s\") = \"%s\"\n", src, strcpy(dst, src));
    printf("\n");

    src[0] = 'H';
    src[1] = 'e';
    src[2] = '\0';
    printf("ft_strcpy(dst, \"%s\") = \"%s\"\n", src, ft_strcpy(dst, src));
    printf("strcpy(dst, \"%s\") = \"%s\"\n", src, strcpy(dst, src));
    printf("\n");

    src[0] = 'H';
    src[1] = 'e';
    src[2] = 'l';
    src[3] = '\0';
    printf("ft_strcpy(dst, \"%s\") = \"%s\"\n", src, ft_strcpy(dst, src));
    printf("strcpy(dst, \"%s\") = \"%s\"\n", src, strcpy(dst, src));
    printf("\n");

    src[0] = 'H';
    src[1] = 'e';
    src[2] = 'l';
    src[3] = 'l';
    src[4] = 'o';
    src[5] = '\0';
    printf("ft_strcpy(dst, \"%s\") = \"%s\"\n", src, ft_strcpy(dst, src));
    printf("strcpy(dst, \"%s\") = \"%s\"\n", src, strcpy(dst, src));
    printf("\n");
}
