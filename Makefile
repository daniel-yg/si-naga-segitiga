CC = g++
INCLUDEFLAG = -I"C:/glfw-3.2.1.bin.WIN64/include" -I"C:\Program Files\mingw-w64\x86_64-8.1.0-win32-seh-rt_v6-rev0\mingw64\x86_64-w64-mingw32\include" -I"C:\glew-2.1.0\include"
LIBPATH = -L"C:/glfw-3.2.1.bin.WIN64/lib-mingw-w64" -L"C:/glew-2.1.0/lib/Release/x64"
LIBFLAG = -lglfw3 -lglew32 -lopengl32 -lglu32 -lgdi32 

all: main.cpp
	$(CC) -o main main.cpp $(INCLUDEFLAG) $(LIBPATH) $(LIBFLAG)