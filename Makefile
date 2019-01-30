all:
	gcc `pkg-config --cflags gtk+-3.0` *.c -o GeradorRecibo `pkg-config --libs gtk+-3.0`
	./GeradorRecibo

