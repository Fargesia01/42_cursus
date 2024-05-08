#ifndef LIBASM_H
#define LIBASM_H

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>

// Assembly functions
int     ft_strlen(char *str);
char    *ft_strcpy(char *dst, char *src);
int     ft_strcmp(char *s1, char *s2);
int     ft_write(int fd, char *str, int len);
int     ft_read(int fd, char *str, int len);
char    *ft_strdup(char *str);

// Test functions
void    test_ft_strlen();
void    test_ft_strcpy();
void    test_ft_strcmp();
void    test_write();
void    test_read();
void    test_ft_strdup();

#endif
