ifeq ($(origin CXX), default)
CXX = c++
endif

ifeq ($(origin RM), default)
RM = rm -rf
endif

TARGET = fixed
override CXXFLAGS += -Wall -Wextra -Werror -std=c++98

SRCS =	main.cpp \
		Fixed.cpp

HEADERS = Fixed.hpp

all: $(TARGET)
 
$(TARGET): $(SRCS) Makefile $(HEADERS)
	$(CXX) -I. $(CXXFLAGS) $(SRCS) -o $@ 

clean: 

fclean: clean
	$(RM) $(TARGET) 

re: fclean all

.PHONY: all clean fclean re

