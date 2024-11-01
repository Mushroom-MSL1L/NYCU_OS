make clean
make distclean
make
timeout 1 ../build.linux/nachos -d t -e consoleIO_test1 -d t -e consoleIO_test2
echo "done"