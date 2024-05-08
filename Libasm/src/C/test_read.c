#include "libasm.h"

void test_read() {
    int fd;
    int ret;
    char buf[100];

    system("touch test.txt");
    system("echo \"Hello World!\" > test.txt");
    system("echo \"2nd line\" >> test.txt");

    fd = open("test.txt", O_RDONLY);

    ret = ft_read(fd, buf, 13);
    buf[ret] = '\0';
    printf("Number of bytes read: %d\n", ret);
    printf("Buffer: %s", buf);

    ret = ft_read(fd, buf, 9);
    buf[ret] = '\0';
    printf("Number of bytes read: %d\n", ret);
    printf("Buffer: %s", buf);

    ret = ft_read(fd, buf, 9);
    buf[ret] = '\0';
    printf("Number of bytes read: %d\n", ret);
    printf("Buffer: %s\n", buf);

    ret = ft_read(10, buf, 9);
    printf("Number of bytes read: %d\n", ret);

    close(fd);

    system("rm test.txt");
}
