cd bin
rm programme.exe
cd ..
gcc src/main.c  src/cc2d_graphics.c -Iinclude -Llib -lSDL2main -lSDL2 -lSDL2_image -o bin/programme.exe
cd bin
./programme.exe
