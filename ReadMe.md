# winapiext-tcc
a winapi header completion for Tiny C Compiler to compile win32 programs (also for RawGdiplus)

folders:
- winapiext: just a copy of full winapi headers in [winapi-full-for-0.9.27](http://download.savannah.gnu.org/releases/tinycc/winapi-full-for-0.9.27.zip "winapi-full-for-0.9.27") with windows.h deleted, so that it could directly included as an include path`-Iwinapiext`, to support all winapi features in [Tiny C Compiler](http://download.savannah.gnu.org/releases/tinycc/tcc-0.9.27-win64-bin.zip "Tiny C Compiler").
- winapigdip: minimal winapi support for RawGdiplus
	- how to create: write a code that uses RawGdiplus(just like [RawGdiplus-tcc](https://github.com/Lasereyes5/RawGdiplus-tcc "RawGdiplus-tcc")) and compile the code with argument`-vv`(also include winapiext), then use some editors clean and sort the pathes listed in output, get the minimal includes to winapiext, and finally use some scripts (like batch script) to copy included winapi headers automatically by read some of minimal includes list, "winapigdip" get!
