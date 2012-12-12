CC    ?= clang
CXX   ?= clang++

EXE = my_wc

CDEBUG = -g -Wextra  -Wall  -Waddress -ggdb\
         -fcheck-new  -gstabs 

CXXDEBUG = -g -Wall  -Waddress -ggdb\
            -fcheck-new  -Wstrict-null-sentinel 

CFLAGS = -O0  #$(CDEBUG)
CXXFLAGS = -O0  #$(CXXDEBUG)

CSTD = -std=c99
CXXSTD = -std=c++11

CPPOBJ = main mc_driver
SOBJ =  parser lexer

LIBS = -lfl

FILES = $(addsuffix .cpp, $(CPPOBJ))

OBJS  = $(addsuffix .o, $(CPPOBJ))

CLEANLIST =  $(addsuffix .o, $(OBJ)) $(OBJS) \
				 mc_parser.tab.cc mc_parser.tab.hh \
				 location.hh position.hh \
			    stack.hh mc_parser.output parser.o \
				 lexer.o lex.yy.cc $(EXE)\

.PHONY: all
all: wc

wc: $(FILES)
	$(MAKE) $(SOBJ)
	$(MAKE) $(OBJS)
	$(CXX) $(CXXFLAGS) $(CXXSTD) -o $(EXE) $(OBJS) parser.o lexer.o $(LIBS)
	rm -rf *.o


parser: mc_parser.yy
	bison -d -v mc_parser.yy
	$(CXX) -O0 -g -Wall -c -o parser.o mc_parser.tab.cc

lexer: mc_lexer.l
	flex $<
	$(CXX)  -O0 -g -Wall -c lex.yy.cc -o lexer.o

%.o: %.cpp
	$(CXX) -c $(CXXFLAGS) $(CXXSTD) -o $@ $<

.PHONY: clean
clean:
	rm -rf $(CLEANLIST)

