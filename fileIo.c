#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
 
int main(void)
{
	printf("Hi 1\n");
    int filedesc = open("testfile.txt", O_CREAT | O_RDWR, S_IRWXU | S_IRWXG | S_IRWXO);
 
    if (filedesc < 0) {
		printf("Hi 2\n");
        return -1;
    }
 
    if (write(filedesc, "That wont be output to testfile\n", 32) != 32) {
		printf("Hi 3\n");
        write(2, "There was an error writing to testfile.txt\n", 43);
        return -1;
    }

	printf("Hi 4\n");

	if (close(filedesc) < 0) {
		return -1;
	}
	printf("Hi 5\n");
 
    return 0;
}
