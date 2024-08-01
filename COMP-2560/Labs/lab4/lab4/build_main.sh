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

echo "Running the main program"
./main
