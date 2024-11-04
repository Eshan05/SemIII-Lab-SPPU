# DSL | CGL | OOPL Codes

This repository contains **all** the codes for the 3 labs present in *SPPU Semester III Computer*. You can find syllabus PDF [online](https://pict.edu/time_table_syllabus/CE/SE-Computer-Engg-2019-Patt.pdf). Total codes are (DSL) 32 + (CGL) 16 + (OOPL) 7, this also includes the alternative questions in CGL, all the problem statements are in `README` file in each folder. The following languages and libraries are used in each of the lab. 

- [`DSL`](https://github.com/Eshan05/SemIII-Lab-SPPU/tree/main/DSL): Python 3 and C++17
- [`CGL`](https://github.com/Eshan05/SemIII-Lab-SPPU/tree/main/CGL): C/C++ along with `graphics.h` and OpenGL libraries
- [`OOPL`](https://github.com/Eshan05/SemIII-Lab-SPPU/tree/main/OOPL): Only C++17

To compile in **DSL** use `python ...` or `python3 ...` and `g++ ...`. For **CGL** if `graphics.h` ([Installation](https://www.geeksforgeeks.org/add-graphics-h-c-library-gcc-compiler-linux/)) is used then include `-lgraph` flag at the end as `g++ ... -lgraph`, if compiling while using `OpenGL` libraries then use flags `g++ ... -lglut -lGLU -lGL` (For windows [see here](https://github.com/Eshan05/C-Things/blob/main/Graphics/Notice.md#compiling)). For **OOPL** just use `g++ ...`

## Additional Notes

1. ⭐ Star this repo if you found it useful!
2. If you find any errors or something missing then feel free to report it
3. In DSL `Pure` means without using the in-built functions. Rest are self-explanatory
4. Do abide by the (Modified) MIT License
5. ### If you want to run `graphics.h`
    1. I would suggest **DO NOT** dual boot solely for the purpose of `graphics.h`, if anything you should dualboot for everything BUT `graphics.h`
    2. Instead just get either VirtualBox or some other VM and install `Ubuntu 16.x` (Xenial) and then follow the GFG tutorial (You may come across `guile` error which you can solve by using steps in [AskUbuntu](https://askubuntu.com/a/1120362)
    3. Now do `graphics.h` programming in the VM. Take screenshots with `PRINT SCREEN` and mail them to yourself

## IMP

Don't use these code and outputs directly. A lot of them (As of right now) use in-built functions and other libraries not supposed to be used. Change in progress 