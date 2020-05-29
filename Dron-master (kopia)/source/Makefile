CPPFLAGS= -c -g -Wall -pedantic -std=c++17 

__start__: example.out
	./example.out

example.out: Dr3D_gnuplot_api.o example.o
	g++ -o example.out example.o Dr3D_gnuplot_api.o -lpthread

example.o: example.cpp Dr3D_gnuplot_api.hhh
	g++ ${CPPFLAGS} -o example.o example.cpp

Dr3D_gnuplot_api.o: Dr3D_gnuplot_api.cpp Dr3D_gnuplot_api.hhh
	g++ ${CPPFLAGS} -o Dr3D_gnuplot_api.o Dr3D_gnuplot_api.cpp

Dr3D_gnuplot_api.hhh: Draw3D_api_interface.hhh
	touch Dr3D_gnuplot_api.hhh

clear:
	rm example.out example.o Dr3D_gnuplot_api.o
