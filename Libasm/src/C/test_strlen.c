#include "libasm.h"

void    test_ft_strlen() {
    char *str = "Hello World!";
    printf("ft_strlen(\"%s\") = %d\n", str, ft_strlen(str));
    printf("strlen(\"%s\") = %ld\n", str, strlen(str));
    printf("\n");

    str = "";
    printf("ft_strlen(\"%s\") = %d\n", str, ft_strlen(str));
    printf("strlen(\"%s\") = %ld\n", str, strlen(str));
    printf("\n");

    str = "Hello World!\0";
    printf("ft_strlen(\"%s\") = %d\n", str, ft_strlen(str));
    printf("strlen(\"%s\") = %ld\n", str, strlen(str));
    printf("\n");

    str = "Hello World!\0\0";
    printf("ft_strlen(\"%s\") = %d\n", str, ft_strlen(str));
    printf("strlen(\"%s\") = %ld\n", str, strlen(str));
    printf("\n");

    str = "Hello World!\0\0\0";
    printf("ft_strlen(\"%s\") = %d\n", str, ft_strlen(str));
    printf("strlen(\"%s\") = %ld\n", str, strlen(str));
    printf("\n");

    str = "Hello World!\0\0\0\0";
    printf("ft_strlen(\"%s\") = %d\n", str, ft_strlen(str));
    printf("strlen(\"%s\") = %ld\n", str, strlen(str));
    printf("\n");
}
