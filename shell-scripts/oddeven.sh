echo "Reading the number to check if odd or even..."
read num
flag=$((num%2))
if [ $flag -eq 0 ]
	then
		echo "The given number is even"
	else
		echo "The given number is odd"
fi
