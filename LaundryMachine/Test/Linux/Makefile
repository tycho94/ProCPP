CFLAGS=-Wall -Werror -g -O0 -I../.. -I.. -I../gtest

LFLAGS=-lpthread

BIN=LaundryMachineTest

MAIN_SOURCES=../DeviceUnderTest.cpp

HARNASS_SOURCES=../StubHardwareControl.cpp ../TestCoinWallet.cpp

TEST_SOURCES=../gtest/src/gtest-all.cc ../gtest/src/gtest_main.cc

HEADERS=../../*.h ../*.h

GCC=g++

all: $(BIN)

$(BIN): $(MAIN_SOURCES) $(HARNASS_SOURCES) $(TEST_SOURCES) $(HEADERS)
	$(GCC) $(CFLAGS) $(TEST_SOURCES) $(HARNASS_SOURCES) $(MAIN_SOURCES) $(LFLAGS) -o $@

clean:
	rm -f $(BIN)