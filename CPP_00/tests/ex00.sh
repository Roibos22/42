#!/bin/bash

make re -C ../ex00 > /dev/null 2>&1

# Executable Path
executable="../ex00/megaphone"

# List of inputs
inputs=(	
	' '
	'    '
	'hello world'
	'"shhhhh... I think the students are asleep..."'
	'Damnit ! "Sorry students, I thought this thing was off."'
	'0123456789'
	'"42 is <3!"'
)

echo -e "++++++++++ START TEST EX00 ++++++++++"

# Loop through input
for input in "${inputs[@]}"
do
	echo -e "\nTESTING: '$input'"
	# Use eval to handle multiple arguments stored as a single string
	eval "valgrind --leak-check=full -q $executable $input > output.txt 2>&1"
	cat output.txt
done

make fclean -C ../ex00 > /dev/null 2>&1

echo -e "\n++++++++++ FINISH TEST EX00 ++++++++++"

# Remove the output file
rm output.txt