# compiler: gcc for C program, define as g++ for C++
CC = g++

# compiler flags:
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS = -g -Wall -lsqlite3

# the build target executable:
TARGET = run
SOURCES = main.cpp Member.cpp Provider.cpp Reports.cpp Provider_interface.cpp Manager_interface.cpp Manager_db.cpp Provider_db.cpp General_db.cpp

all:
	$(CC) -o $(TARGET) $(SOURCES) $(CFLAGS)

clean:
	rm $(TARGET) 
