# Makefile for Separate Compilation Example

# *****************************************************
# Parameters to control Makefile operation

CXX = g++

# flag -g set for debugging

CXXFLAGS = -Wall -g

# ****************************************************
# Entries to bring the executable up to date

game: menu.o deck.o card.o marble.o
	$(CXX) $(CXXFLAGS) -o game menu.o deck.o card.o marble.o

menu.o: deck.h card.h marble.h monte.h tool.h rock.h paper.h scissors.h node.h list.h playinghand.h discardpile.h

deck.o: deck.h card.h stack.h

card.o: card.h

marble.o: marble.h
