# RawGdiplus-tcc
C language version GDI+, forked to support Tiny C Compiler.

Folders:
- GdipExt: Extension functions for RawGdiplus
- winapigdip: minimal winapi support for RawGdiplus, created from [winapiext-tcc](https://github.com/Lasereyes5/winapiext-tcc "winapiext-tcc")

Files:
- tccFix.h: annotations and some macro define completions
- test.c: test code to this template ( generate "test.png")
- test.exe: compiled test code
- build.bat: build test code with tcc
- winapigdip.txt: minimal winapi includes as text list(using in [winapiext-tcc](https://github.com/Lasereyes5/winapiext-tcc "winapiext-tcc"))
