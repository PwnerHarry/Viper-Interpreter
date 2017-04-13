del a.exe
del mfcalc.exe
del mfcalc.tab.c
win_bison mfcalc.y
g++ mfcalc.tab.c
ren a.exe mfcalc.exe
pause