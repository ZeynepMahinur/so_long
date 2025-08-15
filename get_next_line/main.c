#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include "get_next_line_bonus.h"


/*int number(int n)
{
    static int num = 0;
    num += n;
    return (num);
}*/
/*int main()
{
   int result =0;
   result = number(5);
   printf("%d\n",result);
   result = number(7);
   printf("%d\n",result);
   result = number(10);
   printf("%d\n",result);
}*/

/*int main()
{
    int fd1 = open("text1.txt", O_RDONLY);
    int fd2 = open("text2.txt", O_RDONLY);
    int fd3 = open("text3.txt", O_RDONLY);
    char *line;
    while((line = get_next_line(fd1)))
    {
        printf("fd1: %s\n", line);
        free (line);
    }
    while((line = get_next_line(fd2)))
    {
        printf("fd2: %s\n", line);
        free (line);
    }
    while ((line = get_next_line(fd1)))
    {
        printf("fd1: %s\n", line);
        free (line);
    }
    close(fd1);
    close(fd2);
    close(fd3);
}*/

int main()
{
    char *line;
    char **lines = NULL;
    int count = 0;
    int i;
    int fd = open("text.txt", O_RDONLY);

    while ((line = get_next_line(fd)) != NULL)
    {
        char **temp = malloc(sizeof(char *) * (count + 2));
        if (!temp)
            return (1);
        i = 0;
        while (i < count)
        {
            temp[i] = lines[i];
            i++;
        }
        temp[count] = line;
        temp[count + 1] = NULL;

        free (lines);
        lines = temp;
        count++;
    }
    close (fd);

    i = count - 1;
    while (i >= 0)
    {
        printf("%s", lines[i]);
        free (lines[i]);
        i--;
    }
    free (lines);
}