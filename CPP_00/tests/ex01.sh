#!/bin/bash

# Executable Path
executable="../ex01/phonebook"

# Output file
output_file="output.txt"

# Redirect all output to a file
exec > "$output_file"

echo -e "++++++++++ START TEST EX01 ++++++++++"

make re -C ../ex01 > /dev/null 2>&1

mkfifo mypipe

eval valgrind --leak-check=full -q $executable < mypipe &
valgrind_pid=$!

# Add your commands here...
echo "ADD" > mypipe

#echo "\n" > mypipe
echo "ADD" > mypipe
echo "1LEON" > mypipe
echo "1Grimmeisen" > mypipe
echo "1lgrimmei" > mypipe
echo "111111111111" > mypipe
echo "1NO SECRETS" > mypipe

echo "ADD" > mypipe
echo "2LEON" > mypipe
echo "2Grimmeisen" > mypipe
echo "2lgrimmei" > mypipe
echo "222222222222" > mypipe
echo "2NO SECRETS" > mypipe

echo "ADD" > mypipe
echo "3LEON" > mypipe
echo "3Grimmeisen" > mypipe
echo "3lgrimmei" > mypipe
echo "333333333333" > mypipe
echo "3NO SECRETS" > mypipe

echo "ADD" > mypipe
echo "4LEON" > mypipe
echo "4Grimmeisen" > mypipe
echo "4lgrimmei" > mypipe
echo "444444444444444" > mypipe
echo "4NO SECRETS" > mypipe

echo "ADD" > mypipe
echo "5LEON" > mypipe
echo "5Grimmeisen" > mypipe
echo "5lgrimmei" > mypipe
echo "555555555555" > mypipe
echo "5NO SECRETS" > mypipe

echo "ADD" > mypipe
echo "6LEON" > mypipe
echo "6Grimmeisen" > mypipe
echo "6lgrimmei" > mypipe
echo "666666666666666" > mypipe
echo "6NO SECRETS" > mypipe

echo "ADD" > mypipe
echo "7LEON" > mypipe
echo "7Grimmeisen" > mypipe
echo "7lgrimmei" > mypipe
echo "77777777777777" > mypipe
echo "7NO SECRETS" > mypipe

echo "ADD" > mypipe
echo "8LEON" > mypipe
echo "8Grimmeisen" > mypipe
echo "8lgrimmei" > mypipe
echo "8888888888888888" > mypipe
echo "8NO SECRETS" > mypipe

echo "SEARCH" > mypipe
echo "1" > mypipe

echo "ADD" > mypipe
echo "9LEON" > mypipe
echo "9Grimmeisen" > mypipe
echo "9lgrimmei" > mypipe
echo "9999999999999999" > mypipe
echo "9NO SECRETS" > mypipe

echo "SEARCH" > mypipe
echo "4" > mypipe

echo "ADD" > mypipe
echo "10LEON" > mypipe
echo "10Grimmeisen" > mypipe
echo "10lgrimmei" > mypipe
echo "101010101010" > mypipe
echo "10NO SECRETS" > mypipe

echo "SEARCH" > mypipe
echo "4" > mypipe

echo "SEARCH" > mypipe
echo "0" > mypipe

echo "SEARCH" > mypipe
echo "9" > mypipe

echo "EXIT" > mypipe


exec 3>&-

make fclean -C ../ex01 > /dev/null 2>&1
wait $valgrind_pid

exec 1>&-

# Open the file descriptor for standard output
exec 1>/dev/tty

cat output.txt

# Print the complete file to the terminal
cat "$output_file"

echo -e "\n++++++++++ FINISH TEST EX01 ++++++++++"

# Optionally, remove the output file
rm -f mypipe
rm "$output_file"