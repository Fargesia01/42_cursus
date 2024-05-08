#include "libasm.h"

void test_write() {
    system("touch test.txt");
    int fd;
    int ret;

    fd = open("test.txt", O_WRONLY);

    ret = ft_write(fd, "Hello World!\n", 13);
    printf("Number of bytes written: %d\n", ret);
    system("cat test.txt");

    ret = ft_write(1, "test\n", 5);
    printf("Number of bytes written: %d\n", ret);

    ret = ft_write(fd, "2nd line\n", 9);
    printf("Number of bytes written: %d\n", ret);
    system("cat test.txt");

    ret = ft_write(1, "", 0);
    printf("Number of bytes written: %d\n", ret);

    ret = ft_write(11, "testt\n", 5);
    printf("ft_write(10, \"test\\n\", 5) = %d\n", ret);

    close(fd);

    system("rm test.txt");
}
