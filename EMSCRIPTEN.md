# Emscripten

## Build

```
emmake make
```

## Link

```
emcc -flto -O3 -fno-rtti -fno-exceptions */*.o */*/*.o main.o -o index.html -sUSE_SDL=2 -sUSE_SDL_MIXER=2 -sSDL2_MIXER_FORMATS='["ogg","mp3"]' -sUSE_SDL_IMAGE=2 -sSDL2_IMAGE_FORMATS='["png"]' -sUSE_SDL_TTF=2 -sASYNCIFY -sASYNCIFY_IGNORE_INDIRECT -sASYNCIFY_ONLY=@../../funcs.txt -sENVIRONMENT=web --preload-file ../../data/@data/ --preload-file ../../fonts/@fonts/ --preload-file ../../gfx/@gfx/ --preload-file ../../music/@music/ --preload-file ../../sound/@sound/ --closure 1 -sEXPORTED_RUNTIME_METHODS=['allocate'] -Wl,-u,fileno
```
