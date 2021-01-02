@echo off
doskey ls=dir $*
call "C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Auxiliary\Build\vcvarsall.bat" x64
set path=w:\adventofcode2020\misc\;%path%