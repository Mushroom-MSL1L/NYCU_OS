# only for jenkins 
make clean 
make 

../build.linux/nachos -e halt
../build.linux/nachos -e consoleIO_test1
../build.linux/nachos -e consoleIO_test2
../build.linux/nachos -e fileIO_test1
../build.linux/nachos -e fileIO_test2