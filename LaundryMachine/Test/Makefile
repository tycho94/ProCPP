# compiler
CC=g++
# compier flags
CFLAGS=-Wall -Werror -Wextra -g -O0 -Igtest
# linker flags (because of gtest)
LFLAGS=-lpthread

# name of executable
BIN=LaundryMachineTest
# mocked controller files with tests
SRC=./StubHardwareControl.cpp \
	./TestCoinWallet.cpp \
	./TestBuzzer.cpp \
	./MockCoinWallet.cpp
HEADERS=../*.h ./*.h
# gtest sources
GTEST=./gtest/src/gtest-all.cc ./gtest/src/gtest_main.cc


all: clean $(BIN)

$(BIN): $(SRC) $(GTEST) $(HEADERS)
	$(CC) $(CFLAGS) $(LFLAGS) $(GTEST) $(SRC) -o $@

clean:
	@# bash script to check if the file exists, if it does remove it.
	@if [ -a $(BIN) ]; then rm -f $(BIN); fi;
