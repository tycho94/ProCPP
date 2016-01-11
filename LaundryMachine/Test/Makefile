# compiler
CC=g++
# compier flags
CFLAGS=-Wall -Werror -Wextra -g -O0 -Igtest
# linker flags (because of gtest)
LFLAGS=-lpthread
#flags for samuel
MFLAGS=-I /usr/include/gtest/ -L /usr/lib/

# name of executable
BIN=LaundryMachineTest
# mocked controller files with tests
SRC=./StubHardwareControl.cpp \
	./TestCoinWallet.cpp \
	./TestBuzzer.cpp \
	./MockCoinWallet.cpp \
	./TestLock.cpp
HEADERS=../*.h ./*.h
# gtest sources
GTEST=./gtest/src/gtest-all.cc ./gtest/src/gtest_main.cc


all: clean $(BIN)

$(BIN): $(SRC) $(GTEST) $(HEADERS)
	$(CC) $(CFLAGS) $(SRC) -o $@ $(MFLAGS) $(GTEST) $(LFLAGS)

clean:
	@# bash script to check if the file exists, if it does remove it.
	@if [ -f $(BIN) ]; then rm -f $(BIN); fi;
