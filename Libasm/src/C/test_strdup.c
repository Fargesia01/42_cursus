#include "libasm.h"

void test_ft_strdup() {
    char *str;
    char *dup;

    str = "Hello World!";
    dup = ft_strdup(str);
    printf("Original: %s\n", str);
    printf("Duplicate: %s\n", dup);
    free(dup);

    str = "";
    dup = ft_strdup(str);
    printf("Original: %s\n", str);
    printf("Duplicate: %s\n", dup);
    free(dup);

    str = "This is a test string.";
    dup = ft_strdup(str);
    printf("Original: %s\n", str);
    printf("Duplicate: %s\n", dup);
    free(dup);
}
