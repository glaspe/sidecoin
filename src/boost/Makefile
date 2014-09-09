CC = mpic++
CXXFLAGS = -g -W -Wall -Werror
LIBS = -lboost_mpi -lboost_serialization -lboost_system -lboost_filesystem -lboost_graph_parallel -lboost_iostreams

all: Boost

Boost: Boost.o
	$(CC) $(CXXFLAGS) -o Boost Boost.o $(LIBS)

Boost.o: Boost.cpp
	$(CC) $(CXXFLAGS) -c Boost.cpp

clean:
	$(RM) Boost Boost.o
