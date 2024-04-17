all: app

app: loader.o geometry_objects.o app.o
	g++ loader.o geometry_objects.o app.o -o app

app.o: main.cpp
	g++ -c main.cpp -o app.o

loader.o: loader.cpp
	g++ -c loader.cpp -o loader.o

geometry_objects.o: geometry_objects.cpp
	g++ -c geometry_objects.cpp -o geometry_objects.o

clean:
	rm *.o app
