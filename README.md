# Purpose

Library to convert jpeg format images onto png.

# Dependencies

sudo apt install \
    libjpeg-dev \
    libpng-dev

# Build

You need first to create the library.

```
    - cd <path-to-project-root>
    - make re
```


Library will be in /lib folder.

# Test

After creating library

## Build

```
    - cd <path-to-project-root>/test
    - make re
```

## Exe

```
    - ./img-converter <path-to-jpg-file-to-convert>/<jpg-file-name.jpg> <path-to-destination>/<png-file-name-to-create>.png
```