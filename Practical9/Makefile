CC = gcc
CFLAGS = -Wall -Wextra -O2

all: copy_lowlevel copy_stdio redirect_output

copy_lowlevel: copy_lowlevel.c
	$(CC) $(CFLAGS) copy_lowlevel.c -o copy_lowlevel

copy_stdio: copy_stdio.c
	$(CC) $(CFLAGS) copy_stdio.c -o copy_stdio

redirect_output: redirect_output.c
	$(CC) $(CFLAGS) redirect_output.c -o redirect_output

clean:
	rm -f copy_lowlevel copy_stdio redirect_output
	rm -f input.dat output_low.dat output_low2.dat
	rm -f output_stdio.dat output_stdio2.dat output.txt
