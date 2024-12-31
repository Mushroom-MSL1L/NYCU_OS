cd ../build.linux
make distclean
make depend
make
make clean
cd ../test

make distclean
make 
rm -f *.o *.ii
rm -f *.coff
echo "=========================="
timeout 1 ../build.linux/nachos -d z -ep mp4_consoleIO_1 60 -ep mp4_consoleIO_2 70 
echo "=========================="
timeout 1 ../build.linux/nachos -d z -ep mp4_consoleIO_1 70 -ep mp4_consoleIO_2 60
echo "=========================="
timeout 1 ../build.linux/nachos -ep mp4_consoleIO_1 70 -ep mp4_consoleIO_3 80 -ep mp4_consoleIO_2 50
echo "done"