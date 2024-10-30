# should be run from the test directory
make -C ../build.linux distclean
make -C ../build.linux depend
make -C ../build.linux
make -C ../build.linux clean

make distclean
make 
make clean

../build.linux/nachos -e halt
../build.linux/nachos -e consoleIO_test1
../build.linux/nachos -e consoleIO_test2
../build.linux/nachos -e fileIO_test1
../build.linux/nachos -e fileIO_test2