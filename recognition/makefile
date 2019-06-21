main:compile
	./main /usr/share/opencv/haarcascades/haarcascade_frontalface_alt2.xml ../training/training.txt 0
compile:clean
	g++ -o main main.cpp `pkg-config --cflags --libs opencv`
clean:
	rm main.o main || true
