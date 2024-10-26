CXX = g++
CXXFLAGS = -std=c++17
SRCS = CLI/Command.cpp CLI/CommandCreatir.cpp ClI/CommandInfo.cpp CLI/main.cpp CLI/Parser.cpp CLI/SlideMaker.cpp Document/Attributes.cpp Document/Document.cpp Document/Slide.cpp 
OBJS = $(SRCS:.cpp=.o)
EXEC = PPT_Console

all: $(EXEC)

$(EXEC): $(OBJS)
  $(CXX) $(CXXFLAGS) $(OBJS) -o $(EXEC) -lncurses

%.o: %.cpp
  $(CXX) $(CXXFLAGS) -c $< -o $@

clean:
  rm -f $(OBJS) $(EXEC)