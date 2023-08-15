echo "Fetching operand 1... "
read a

echo "Fetching operand 2... "
read b

i="y"


while [ $i = "y" ]
do
	echo "1) ADD 2) SUB 3) MUL 4) DIV"

	read opt

	case $opt in
		1)res=$((a+b))
			;;
		2)res=$((a-b))
			;;
		3)res=$((a*b))
			;;
		4)res=$((a/b))
			;;
	esac
	echo "Result -> $res"

	echo "Do you wanna continue? "
	read i

	if [ $i != "y" ]
	then
		exit 0
	fi

done
