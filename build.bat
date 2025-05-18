@echo off
title Lain
set cc=tcc
set files=test.c
set includes=-Iwinapigdip
REM set libs=-lgdiplus
REM set defines=-D
set args=%includes% %libs% %defines% %files%

%cc% %args%