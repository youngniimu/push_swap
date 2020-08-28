#!/bin/bash
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
# if [$nb = "visu"]; then
# 		ARG=$(seq $nb | shuf) ; ./push_swap $ARG | wc -l ; ./push_swap $ARG | ./checker -v $ARG
# 	else
# 		for (( c=0; c<=count; c++ ))
# 			do  
# 				ARG=$(seq $nb | shuf) ; ./push_swap $ARG | wc -l ; ./push_swap $ARG | ./checker $ARG
# 			done
# fi