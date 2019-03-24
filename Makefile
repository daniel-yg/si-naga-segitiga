CC = gcc
INCLUDEPATH = C:/glfw-3.2.1.bin.WIN64/include
INCLUDEFLAG = -I$(INCLUDEPATH)
LIBPATH = -L"C:/glfw-3.2.1.bin.WIN64/lib-mingw-w64"
LIBFLAG = -lglfw3 -lopengl32 -lglu32 -lgdi32

all: main.c
	$(CC) -o main main.c $(INCLUDEFLAG) $(LIBPATH) $(LIBFLAG)