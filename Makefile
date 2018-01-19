main: main.o controller.o controller_gui.o view.o view_gui.o emporium.o serving.o order.o server.o customer.o items.o container.o scoop.o toppings.o main_window.o dialogs.o
	g++ --std=c++11 main.o controller.o controller_gui.o view.o view_gui.o emporium.o serving.o order.o server.o customer.o items.o container.o scoop.o toppings.o main_window.o dialogs.o -o main `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`
	./main
main.o: main.cpp
	g++ --std=c++11 -c main.cpp `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`
main_window.o: main_window.cpp main_window.h
	g++ --std=c++11 -c main_window.cpp `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`
dialogs.o: dialogs.cpp dialogs.h
	g++ --std=c++11 -c dialogs.cpp `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`
controller.o: controller.cpp controller.h
	g++ --std=c++11 -c controller.cpp `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`
controller_gui.o: controller_gui.cpp controller_gui.h
	g++ --std=c++11 -c controller_gui.cpp `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`
view.o: view.cpp view.h
	g++ --std=c++11 -c view.cpp
view_gui.o: view_gui.cpp view_gui.h
	g++ --std=c++11 -c view_gui.cpp `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`
emporium.o: emporium.cpp emporium.h
	g++ --std=c++11 -c emporium.cpp `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`
serving.o: serving.cpp serving.h
	g++ --std=c++11 -c serving.cpp
order.o: order.cpp order.h
	g++ --std=c++11 -c order.cpp
server.o: server.cpp server.h
	g++ --std=c++11 -c server.cpp `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`
customer.o: customer.cpp customer.h
	g++ --std=c++11 -c customer.cpp `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`
items.o: items.cpp items.h
	g++ --std=c++11 -c items.cpp
container.o: container.cpp container.h
	g++ --std=c++11 -c container.cpp
scoop.o: scoop.cpp scoop.h
	g++ --std=c++11 -c scoop.cpp
toppings.o: toppings.cpp toppings.h
	g++ --std=c++11 -c toppings.cpp
clean:
	-rm -f *.o main
