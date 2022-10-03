@ECHO OFF
./generate 100000 10000 99999
time sort numbers.txt > sorted.txt
time ./mySortA numbers.txt  sortedA.txt
time ./mySortV numbers.txt  sortedV.txt
