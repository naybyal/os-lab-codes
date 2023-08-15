echo "Reading number to check whether it's odd or even.... "
read num
check=$((num%2))
if [ $check -eq 0 ]
then
	echo "It's even"
	exit 0
fi

echo "It's odd"
