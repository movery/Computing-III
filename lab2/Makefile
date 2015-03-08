# Makefile for lab2
#
#

all: lab2p1 lab2p2

lab2p2: Invoice.h Invoice.cpp invoice_client.cpp
	g++ --std=c++0x Invoice.cpp invoice_client.cpp -o lab2p2

lab2p1: Account.h Account.cpp account_client.cpp
	g++ --std=c++0x Account.cpp account_client.cpp -o lab2p1

clean:
	rm -f lab2p1 lab2p2 *~
