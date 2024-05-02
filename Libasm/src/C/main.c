#include "libasm.h"

int main() {
    char *str = "Hello, World!";
    int len = ft_strlen(str);
    printf("Length of string (ft_strlen): %d\n", len);  
    printf("Length of string (strlen): %ld\n", strlen(str));

    return (0);
}
