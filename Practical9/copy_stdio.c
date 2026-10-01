#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 8192

int main(int argc, char *argv[])
{
    FILE *src;
    FILE *dest;
    char buffer[BUFFER_SIZE];
    size_t bytes_read;

    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s <source> <destination>\n", argv[0]);
        return 1;
    }

    /* Open source file */
    src = fopen(argv[1], "rb");

    if (src == NULL)
    {
        perror("fopen source");
        return 1;
    }

    /* Open/create destination file */
    dest = fopen(argv[2], "wb");

    if (dest == NULL)
    {
        perror("fopen destination");
        fclose(src);
        return 1;
    }

    /* Copy file */
    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, src)) > 0)
    {
        if (fwrite(buffer, 1, bytes_read, dest) != bytes_read)
        {
            perror("fwrite");
            fclose(src);
            fclose(dest);
            return 1;
        }
    }

    if (ferror(src))
    {
        perror("fread");
        fclose(src);
        fclose(dest);
        return 1;
    }

    fclose(src);
    fclose(dest);

    printf("File copied successfully using standard C I/O.\n");

    return 0;
}
