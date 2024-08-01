#!/bin/bash
echo "Start building main program"
echo "Compiling to assembly lines..."
cc main.c -S
cc increment.c -S
echo "Translating to opcodes..."
cc main.s -c
cc increment.s -c
echo "Statically linking all required opcodes..."
cc main.o increment.o -o main
echo "Build successfully done!"

#echo "Running the main program"
#./main
#echo "Running the main program for input 4: "
#./main <<< 4
#echo "Running the main program for input 10: "
#./main <<< 10
true = 0
false = 0
while read line
do
	#echo "Test the main program for $input"
	input=`echo "$line" | cut -f1 -d','`
	expected=`echo "$line" | cut -f2 -d','`
	output=`./main <<< $input`
	if [ $output = $expected ] 
	then
		true=$((true+1))
		echo "Input: $input, main: $output, correct $expected ==> passed"
	else
		false=$((false+1))
		echo "Input: $input, main: $output, correct $expected ==> failed"
	fi	
done < "./test_inputs.txt"

echo "Total Passed: $true"
echo "Total Failed: $false"
