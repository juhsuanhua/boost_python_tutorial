PYTHON_VERSION = 2.7
PYTHON_INCLUDE = /usr/include/python$(PYTHON_VERSION)
# location of the Boost Python include files and library
BOOST_INC = /usr/include
BOOST_LIB = /usr/lib

CC = g++ -std=c++11
CFLAGS = -I$(PYTHON_INCLUDE) -I$(BOOST_INC) -fPIC
LDFLAGS = -L$(BOOST_LIB) -lboost_python -L/usr/lib/python$(PYTHON_VERSION)/config -lpython$(PYTHON_VERSION)

# compile mesh classes
TARGET = hello_ext
OBJS = world.o small_world.o hello_ext.o
DEPS = world.h small_world.h hello_ext.h

$(TARGET).so: $(OBJS)
	$(CC) -shared -Wl,--export-dynamic $^ $(LDFLAGS) -o $(TARGET).so

%.o: %.cpp $(DEPS)
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm *.o *.so
