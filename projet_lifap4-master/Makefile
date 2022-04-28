EXEC_NAME1 = bin/text
EXEC_NAME2 = bin/sdl

OBJ_FILES1 = obj/mainText.o obj/Application.0 obj/Continent.o obj/Carte.o obj/ElementTD.o obj/Monument.o obj/Pays.o obj/TableauDynamique.o
OBJ_FILES2 = obj/mainSDL.o obj/Application.0 obj/Continent.o obj/Carte.o obj/ElementTD.o obj/Monument.o obj/Pays.o obj/TableauDynamique.o obj/Image.0


INCLUDES =   -Iextern/SDL2_mingw/SDL2-2.0.3/include \
                        -Iextern/SDL2_mingw/SDL2_ttf-2.0.12/i686-w64-mingw32/include/SDL2 \
                        -Iextern/SDL2_mingw/SDL2_image-2.0.0/i686-w64-mingw32/include/SDL2 \
                        -Iextern/SDL2_mingw/SDL2_mixer-2.0.1/i686-w64-mingw32/include/SDL2

LIBS = 		-Lextern/SDL2_mingw/SDL2-2.0.3/i686-w64-mingw32/lib \
            -Lextern/SDL2_mingw/SDL2_ttf-2.0.12/i686-w64-mingw32/lib \
            -Lextern/SDL2_mingw/SDL2_image-2.0.0/i686-w64-mingw32/lib \
            -Lextern/SDL2_mingw/SDL2_mixer-2.0.1/i686-w64-mingw32/lib \
			-lSDL2 -lSDL2_ttf -lSDL2_image
           
CC = g++
CFLAGS = -Wall -ggdb

all: $(EXEC_NAME1) $(EXEC_NAME2) 

$(EXEC_NAME1): $(OBJ_FILES1)
	$(CC) -o $(EXEC_NAME1) $(OBJ_FILES1) $(LIBS)

obj/mainText.o: src/mainText.cpp src/Application.h src/Continent.h src/Carte.h src/ElemenTD.h src/Monument.h src/Pays.h src/TableauDynamique.h
	$(CC) -g $(CFLAGS) $(INCLUDES) -c src/mainText.cpp -o obj/mainText.o

obj/Application.o: src/Application.cpp src/Application.h  src/Carte.h
	$(CC) -g $(CFLAGS)  $(INCLUDES) -c src/Application.cpp -o obj/Application.o

obj/Carte.o: src/Carte.cpp src/Carte.h  src/Continent.h
	$(CC) -g $(CFLAGS) $(INCLUDES) -c src/Carte.cpp -o obj/Carte.o

obj/Continent.o: src/Continent.cpp src/Continent.h src/Pays.h  src/TableauDynamique.h
	$(CC) -g $(CFLAGS) $(INCLUDES) -c src/Continent.cpp -o obj/Continent.o

obj/ElementTD.o: src/ElementTD.cpp ElemenTD.h
	$(CC) -g $(CFLAGS) $(INCLUDES) -c src/ElementTD.cpp -o obj/ElementTD.o

obj/Monument.o: src/Monument.cpp Monument.h
	$(CC) -g $(CFLAGS) $(INCLUDES) -c src/Monument.cpp -o obj/Monument.o

obj/Pays.o: src/Pays.cpp src/Pays.h Monument.h
	$(CC) -g $(CFLAGS) $(INCLUDES) -c src/Pays.cpp -o obj/Pays.o

obj/TableauDynamique.o: src/TableauDynamique.cpp src/TableauDynamique.h ElementTD.h
	$(CC) -g $(CFLAGS) $(INCLUDES) -c src/TableauDynamique.cpp -o obj/TableauDynamique.o

obj/Image.o: src/Image.cpp src/Image.h Image.h
	$(CC) -g $(CFLAGS) $(INCLUDES) -c src/Image.cpp -o obj/Image.o


$(EXEC_NAME2): $(OBJ_FILES2)
	$(CC) -o $(EXEC_NAME2) $(OBJ_FILES2) $(LIBS)

obj/mainSDL.o: src/mainSDl.cpp src/Application.h src/Continent.h src/Carte.h src/ElemenTD.h src/Monument.h src/Pays.h src/TableauDynamique.h src/Image.
	$(CC) -g $(CFLAGS) $(INCLUDES) -c src/mainSDL.cpp -o obj/mainSDL.o



clean:
	rm -f obj/*.o bin/* 


