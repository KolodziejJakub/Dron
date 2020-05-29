CPPFLAGS= -c -g -Wall -pedantic -std=c++17 

__start__: example.out
	./example.out

example.out: Dr3D_gnuplot_api.o example.o Macierz.o dron.o obiekt.o obiektzmozliwosciaruchuirotacji.o powierzchnia.o silnik.o sroba.o taflawody.o Wektor.o przeszkoda.o
	g++ -o example.out example.o Dr3D_gnuplot_api.o Macierz.o dron.o obiekt.o obiektzmozliwosciaruchuirotacji.o powierzchnia.o silnik.o sroba.o taflawody.o Wektor.o przeszkoda.o -lpthread

dron.o: dron.cc dron.hh
	g++ ${CPPFLAGS} -o dron.o dron.cc

Macierz.o: Macierz.cpp Macierz.hh
	g++ ${CPPFLAGS} -o Macierz.o Macierz.cpp


obiekt.o: obiekt.cpp obiekt.hh
	g++ ${CPPFLAGS} -o obiekt.o obiekt.cpp

obiektzmozliwosciaruchuirotacji.o: obiektzmozliwosciaruchuirotacji.cpp obiektzmozliwosciaruchuirotacji.hh
	g++ ${CPPFLAGS} -o obiektzmozliwosciaruchuirotacji.o obiektzmozliwosciaruchuirotacji.cpp

powierzchnia.o: powierzchnia.cpp powierzchnia.hh
	g++ ${CPPFLAGS} -o powierzchnia.o powierzchnia.cpp

silnik.o: silnik.cpp silnik.hh
	g++ ${CPPFLAGS} -o silnik.o silnik.cpp

sroba.o: sroba.cpp sroba.hh
	g++ ${CPPFLAGS} -o sroba.o sroba.cpp

taflawody.o: taflawody.cpp taflawody.hh
	g++ ${CPPFLAGS} -o taflawody.o taflawody.cpp

Wektor.o: Wektor.cpp Wektor.hh
	g++ ${CPPFLAGS} -o Wektor.o Wektor.cpp

example.o: example.cpp Dr3D_gnuplot_api.hh
	g++ ${CPPFLAGS} -o example.o example.cpp

przeszkoda.o: przeszkoda.cpp przeszkoda.hh
	g++ ${CPPFLAGS} -o przeszkoda.o przeszkoda.cpp

Dr3D_gnuplot_api.o: Dr3D_gnuplot_api.cpp Dr3D_gnuplot_api.hh
	g++ ${CPPFLAGS} -o Dr3D_gnuplot_api.o Dr3D_gnuplot_api.cpp

Dr3D_gnuplot_api.hhh: Draw3D_api_interface.hh
	touch Dr3D_gnuplot_api.hh

clear:
	rm example.out example.o Dr3D_gnuplot_api.o Wektor.o taflawody.o sroba.o silnik.o obiektzmozliwosciaruchuirotacji.o powierzchnia.o Macierz.o dron.o obiekt.o
