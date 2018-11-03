all:
	gcc `pkg-config --cflags gtk+-3.0` -o Main main.c `pkg-config --libs gtk+-3.0`
clean:
	rm Main
