CC = gcc
CFLAGS = -c -std=c99
SRC = $(wildcard src/*.c)
HDR = $(wildcard include/*.h)
OBJ = ${SRC:.c=.o}
EXEC = ahatco
LDFLAGS = -g

all: ${SRC} ${OBJ} ${EXEC}
debug: all
debug: CFLAGS += -DDEBUG

${EXEC}: ${OBJ}
	${CC} ${LDFLAGS} $^ -o $@

%.o : %.c ${HDR}
	${CC} ${CFLAGS} $< -o $@

clean:
	rm -f ${OBJ} ${EXEC}

install:
	cp ${EXEC} /usr/local/bin/ahatco
uninstall:
	rm /usr/local/bin/${EXEC}