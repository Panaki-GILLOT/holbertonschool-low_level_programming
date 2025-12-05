#ifndef MAIN_H
#define MAIN_H

#include <stddef.h>  /* pour size_t */
#include <sys/types.h> /* pour ssize_t */

/* Prototype de la fonction read_textfile */
ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);

#endif /* MAIN_H */
