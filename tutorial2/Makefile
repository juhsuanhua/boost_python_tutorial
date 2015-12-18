PYTHON_VERSION = 2.7
PYTHON_INCLUDE = /usr/include/python$(PYTHON_VERSION)
# location of the Boost Python include files and library
BOOST_INC = /usr/include
BOOST_LIB = /usr/lib

CXX = g++
CXXFLAGS = -std=c++11 -I$(PYTHON_INCLUDE) -I$(BOOST_INC) -fPIC
LDFLAGS = -L$(BOOST_LIB) -lboost_python -L/usr/lib/python$(PYTHON_VERSION)/config -lpython$(PYTHON_VERSION)

# compile mesh classes
TARGET = T2
OBJS = T2.o
# DEPS = world.h small_world.h hello_ext.h

$(TARGET).so: $(OBJS)
	$(CXX) -shared -Wl,--export-dynamic $^ $(LDFLAGS) -o $(TARGET).so

%.o: %.cpp
	$(CXX) -c -o $@ $< $(CXXFLAGS)

clean:
	rm *.o *.so
