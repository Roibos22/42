#!/bin/bash

# Executable Path
executable="../ex02/accounting"

echo -e "++++++++++ START TEST EX02 ++++++++++"

make re -C ../ex02 > my_logfile.txt

eval "valgrind --leak-check=full -q $executable > my_logfile.txt"

diff_output=$(diff <(cut -c19- my_logfile.txt) <(cut -c19- 19920104_091532.log) | awk '/^</{print substr($0, 3)}')

# If diff_output is empty, print "No difference found."
# Otherwise, print the differences
if [ -z "$diff_output" ]
then
	echo
	echo "No difference found after timestamps of each line."
else
	echo "$diff_output"
fi

make fclean -C ../ex02 > /dev/null 2>&1
rm -f my_logfile.txt

echo -e "\n++++++++++ FINISH TEST EX02 ++++++++++"

# Remove the output file
