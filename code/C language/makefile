.PHONY: clean build link all

SRC_DIR = src
HEADER_DIR = include
APP_DIR = bin
OBJ_DIR = build

APP_NAME = app.exe

SOURCE_FILE = ${wildcard ${SRC_DIR}/*.c} \
	${wildcard ${SRC_DIR}/helper/*.c}

TARGET = ./${APP_DIR}./${APP_NAME}

clean:
	rm -f *.exe *.o

build:
	gcc ${CFLAGS} ${SOURCE_FILE} -I${HEADER_DIR} -o ${TARGET}

run: 
	${TARGET}

all: build run