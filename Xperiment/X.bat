del a.exe
del X.exe
del X.tab.c
win_bison -d X.y
g++ X.tab.c
ren a.exe X.exe
X