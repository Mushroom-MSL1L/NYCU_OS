make distclean
make 
rm -f *.o *.ii
rm -f *.coff
echo "=========================="
timeout 1 ../build.linux/nachos -ep hw4_consoleIO_1 60 -ep hw4_consoleIO_2 70 
echo "=========================="
timeout 1 ../build.linux/nachos -ep hw4_consoleIO_1 70 -ep hw4_consoleIO_2 60
echo "=========================="
timeout 1 ../build.linux/nachos -ep hw4_consoleIO_1 70 -ep hw4_consoleIO_3 80 -ep hw4_consoleIO_2 50
echo "=========================="
timeout 1 ../build.linux/nachos -d z -ep hw4_console_1 60 hw4_console_2 70
echo "done"