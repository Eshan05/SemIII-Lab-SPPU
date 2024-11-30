# DSL | CGL | OOPL Codes

This repository contains **all** the codes for the 3 labs present in *SPPU Semester III Computer*. You can find syllabus PDF [online](https://pict.edu/time_table_syllabus/CE/SE-Computer-Engg-2019-Patt.pdf). Total codes are (DSL) 32 + (CGL) 16 + (OOPL) 7, this also includes the alternative questions in CGL, all the problem statements are in `README` file in each folder. The following languages and libraries are used in each of the lab. 

- [`DSL`](https://github.com/Eshan05/SemIII-Lab-SPPU/tree/main/DSL): Python 3 and C++17 (To compile programs, use `python ...` or `python3 ...` and `g++ ...` with the name of your file (Make sure the path/directory in your terminal is correct))
- [`CGL`](https://github.com/Eshan05/SemIII-Lab-SPPU/tree/main/CGL): C/C++ along with `graphics.h` and OpenGL libraries. Compilation: For **CGL** if `graphics.h` ([Installation](https://www.geeksforgeeks.org/add-graphics-h-c-library-gcc-compiler-linux/)) is used then include `-lgraph` flag at the end as `g++ ... -lgraph`, if compiling while using `OpenGL` libraries then use flags `g++ ... -lglut -lGLU -lGL` (For windows [see here](https://github.com/Eshan05/C-Things/blob/main/Graphics/Notice.md#compiling)).
- [`OOPL`](https://github.com/Eshan05/SemIII-Lab-SPPU/tree/main/OOPL): Only C++17. Compilation: Just using `g++`.

## Additional Notes

1. ⭐ Star this repo if you found it useful!
2.  Try to attempt the problem yourself too. If you find any errors or something missing then feel free to report it
3. Anywhere, `Pure` means without using the in-built functions. Rest are self-explanatory and are just for exploring, *ignore them*
4. Do abide by the MIT License
5. ### If you want to run `graphics.h`
    1. I would suggest **DO NOT** dual boot solely for the purpose of `graphics.h`, if anything you should dualboot for everything BUT `graphics.h`
    2. Instead just get either VirtualBox or some other VM and install `Ubuntu 16.x` (Xenial) and then follow the GFG tutorial (You may come across `guile` error which you can solve by using steps in [AskUbuntu](https://askubuntu.com/a/1120362)
    3. Now do `graphics.h` programming in the VM. Take screenshots with `PRINT SCREEN` and mail them to yourself

## IMP

1. You can see all files [here](./Files.md)
2. `Pure` is present for those problems where the original program uses something not in syllabus (Range-based for loops **in C++**, `zip`, `list`, `map`, `enumerate`,  or other such python functions, sets, STL functions, libraries like `cctype` or `cin.ignore()` or something else). I kept the original files just as a reference. 
3. Other file names (Like `Extra`, `STL`) are self-explanatory