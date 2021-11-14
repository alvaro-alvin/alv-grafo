# Some Makefile symbols and their meaning (GNU Make)
# @a: the filename of the target of the rule

prefix = .
bindir = $(prefix)/bin
builddir = $(prefix)/build
includedir = $(prefix)/headers
srcdir = $(prefix)/src
docdir = $(prefix)/doc

CXXFLAGS = -g -std=c++17 -pthread
INCLUDES = -I$(includedir) 
LIBS = 



OBJS = $(builddir)/aresta.o $(builddir)/vertice.o $(builddir)/grafo.o   

.PHONY: doc clean all test 

all: main

main: $(OBJS) $(srcdir)/main.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(OBJS) $(srcdir)/main.cpp $(LIBS) -o $(bindir)/grafo_teste


$(builddir)/aresta.o: $(builddir)/vertice.o $(includedir)/Aresta.hpp $(srcdir)/aresta.cpp 
	$(CXX) $(CXXFLAGS) -c $(INCLUDES) $(srcdir)/aresta.cpp -o $@

$(builddir)/vertice.o: $(includedir)/Vertice.hpp $(srcdir)/vertice.cpp 
	$(CXX) $(CXXFLAGS) -c $(INCLUDES) $(srcdir)/vertice.cpp -o $@

$(builddir)/grafo.o: $(builddir)/vertice.o $(builddir)/aresta.o $(includedir)/Grafo.hpp $(includedir)/tree.hh $(includedir)/tree_util.hh
	$(CXX) $(CXXFLAGS) -c $(INCLUDES) $(srcdir)/grafo.cpp -o $@

# creating directories
setup:
	mkdir -p $(bindir)
	mkdir -p $(builddir)

clean:
	rm -fR $(bindir)/*
	rm -fR $(docdir)/*
	rm -fR $(builddir)/*
