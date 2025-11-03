.PHONY: clean build link all

CFLAGS = -Wall

SRC_DIR = src
APP_DIR = bin
OBJ_DIR = build
INCLUDE_DIR = include

HEADER_DIR = ${INCLUDE_DIR} \
	${INCLUDE_DIR}/helper \
	${INCLUDE_DIR}/service \
	${INCLUDE_DIR}/model \
	${INCLUDE_DIR}/file 

DEPS = ${addprefix -I,${HEADER_DIR}}

APP_NAME = app.exe

SRC_FILE = $(wildcard ${SRC_DIR}/*.c) \
	$(wildcard ${SRC_DIR}/helper/*.c) \
	$(wildcard ${SRC_DIR}/model/*.c) \
	$(wildcard ${SRC_DIR}/file/*.c) \
	$(wildcard ${SRC_DIR}/service/*.c) 

TARGET = ${APP_DIR}/${APP_NAME}

clean:
	rm -f *.exe *.o

build:
	gcc ${SRC_FILE} ${DEPS} -o ${TARGET}

run: 
	${TARGET}

all: build run