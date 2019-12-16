# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    correction.sh                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cgiron <cgiron@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/19 17:57:30 by cgiron            #+#    #+#              #
#    Updated: 2019/07/08 19:18:09 by ltimsit-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

################################ Functions #####################################

function usage
{
	printf "usage: correction.sh [-n round nb] [-m map_folder] [-e champion ]\n\
		[-c challenger_folder][-o output_folder] [-wp wait after player]\n\
		[-wm wait after map][-b erase outpute on player change]\n\n"
	printf "Game launcher for the vm playing a champion\n\
		- till n wins\n\
		- against a folder of champion\n\
		- for a folder of map\n\
		- it will crash on invalid map - champion - player\n\
		- it will stop if champion loose\n\
		- use -b in conjunction with wp an wm to check output\n
	- use sh ./correction.sh [] \033[0;32m 2>&1 | tee whoopwhoop.txt\033[0m to store the output and see it\n"
}

########################## Variables initialization ############################

player_eval=../ltimsit-.filler
challenger_folder=players
map_folder=maps
output_folder=correction_output
n_vict=3
score_eval=0
score_chal=0
i=0
rounds=0
wait_map=0
wait_player=0
keepmap=1


############################# Options parser ###################################

while [ "$1" != "" ]
do
	OPT=$1
	case $OPT in
		-h | --help )
			usage
			exit 0
			;;
		-n )
			shift
			n_vict=$1
			;;
		-m )
			shift
			map_folder=$1
			;;
		-e )
			shift
			player_eval=$1
			;;
		-c )
			shift
			challenger_folder=$1
			;;
		-o )
			shift
			output_folder=$1
			;;
		-wm )
			wait_map=1
			;;
		-wp )
			wait_player=1
			;;
		-b )
			keepmap=0
			;;
	esac
	shift
done

################################ Main loop #####################################

echo "EVALUATED PLAYER   :\033[0;32m" $player_eval
echo "\033[0mCHALLENGERS FOLDER :\033[0;32m" $challenger_folder
echo "\033[0mPLAY TILL\033[0;32m" $n_vict "\033[0mWINS"
echo "\033[0mWITH ALL MAPS IN :\033[0;32m" $map_folder
echo "\033[0mOUTPUT IN :\033[0;32m" $output_folder
echo "\033[0mKEEPMAP a:\033[0;32m" $keepmap
echo "\033[0m"

rm -rf $output_folder
mkdir -p $output_folder
seed=$(($RANDOM%10000))

evalstr=$(echo $player_eval | rev | cut -d'/' -f 1 | rev | cut -d'.' -f 1)
for player_chal in $challenger_folder/*.filler
do
	chalstr=$(echo $player_chal | rev | cut -d'/' -f 1 | rev | cut -d'.' -f 1)
	echo "\033[30;1;43m" "PLAYER" $chalstr "STARTING" "\033[0m"
	for map_playing in $map_folder/*
	do
		mapstr=$(echo $map_playing | rev | cut -d'/' -f 1 | rev)
		echo "\033[30;1;42m" "MAP" $mapstr "STARTING" "\033[0m"
		score_eval=0
		score_chal=0
		while [ $score_eval -lt $n_vict ] && [ $score_chal -lt $n_vict ]
		do
			if [ $((i+1)) -lt 10 ]; then
				istr="0$((i+1))"
			else
				istr="$((i+1))"
			fi
			seed=$(($RANDOM%10000))
			echo "round" $istr "- seed:" $seed "- map" $mapstr "-chal" $chalstr
			total=0
			for j in 1 2
			do
				if [ $j -eq 1 ]; then
					printf 'turn a: '
				else
					printf 'turn b: '
				fi
				if [ $j -eq 1 ]; then
					./filler_vm -s $seed -f $map_playing -p1 $player_eval -p2 $player_chal\
						&> $output_folder/"$chalstr"_"$mapstr"_round_"$istr"_output_a
				else
					./filler_vm -s $seed -f $map_playing -p1 $player_chal -p2 $player_eval \
						&> $output_folder/"$chalstr"_"$mapstr"_round_"$istr"_output_b
				fi
				result=$(cat filler.trace | grep AGAINST | sed -e 's/AGAINST/ /g')
				if [ $j -eq 1 ]; then
					score_temp_eval=$(echo $result | cut -d\  -f1)
					score_temp_chal=$(echo $result | cut -d\  -f2)
					echo "p1 - eval: $score_temp_eval ||" "p2 - chal: $score_temp_chal"
				else
					score_temp_chal=$(echo $result | cut -d\  -f1)
					score_temp_eval=$(echo $result | cut -d\  -f2)
					echo "p2 - eval: $score_temp_eval ||" "p1 - chal: $score_temp_chal"
				fi
				if [ -z "$score_temp_eval" ]; then
					echo ""
					echo "NOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO\033[0m"
					echo "\033[39;1;41mCRASH CHECK OUTPUT FILE\033[0m"
					echo "NOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO\033[0m"
					echo ""
					read -p "An error occured - Check if last piece overflow ? (y/n) " answer
					if [ "$answer" == "n" -o "$answer" == "n" ]; then
						exit 1
					fi
				fi
				if [ $score_temp_eval -gt $score_temp_chal ]; then
					((total++))
				elif [ $score_temp_chal -gt $score_temp_eval ]; then
					((total--))
				fi
			done
			if [ $total -eq +2 ]; then
				echo "\033[0;32m" $evalstr "(eval) won the round !\033[0m"
				((score_eval++))
			elif [ $total -eq -2 ]; then
				echo "\033[0;31m" $chalstr "(eval) won the round !\033[0m"
				((score_chal++))
			else
				echo "no clear winner..."
			fi
			((i++))
		done
		if [ $score_eval -lt $n_vict ]; then
			echo ""
			echo "NOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO\033[0m"
			echo "\033[39;1;41mYOU LOST $score_eval to $score_chal EXITING...............\033[0m"
			echo "NOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO\033[0m"
			echo ""
			exit 1
		elif [ $score_chal -lt $n_vict ]; then
			echo ""
			echo "WOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOW\033[0m"
			echo "\033[30;1;107mYOU WON $score_eval to $score_chal proceed with caution...\033[0m"
			echo "WOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOW\033[0m"
			echo ""
			echo "\033[30;1;42m" "MAP" $mapstr "DONE" "\033[0m"
		fi
		i=0;
		if [ $wait_map -ne 0 ]; then
			read -p "continue ? (y/n) " answer
			if [ "$answer" == "n" -o "$answer" == "n" ]; then
				exit 1
			fi
		fi
	done
	echo "\033[30;1;43m" "PLAYER" $chalstr "DONE" "\033[0m"
	if [ $wait_player -ne 0 ]; then
		read -p "continue (y/n) " answer
		if [ "$answer" == "n" -o "$answer" == "n" ]; then
			exit 1
		fi
	fi
	if [ $keepmap -gt 0 ]; then
		rm -rf $output_folder
		mkdir -p $output_folder
	fi
done
