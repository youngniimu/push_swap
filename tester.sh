#!/bin/bash

visualizer=100

clear
echo 1 = run tester
echo 2 = run visualizer
read program
case $program in
	1)
	clear
	echo enter number of arguments:
	read nb
	clear
	echo enter number of test iterations
	read count
	clear

	for (( c=1; c<=count; c++ ))
	do  
		ARG=$(seq $nb | shuf) ; ./push_swap $ARG | wc -l ; ./push_swap $ARG | ./checker $ARG
	done
	;;
	2)
		ARG=$(seq $visualizer | shuf) ; ./push_swap $ARG | ./checker -v $ARG
	;;
esac
