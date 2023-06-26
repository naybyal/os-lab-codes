echo "Reading array size"
read size

echo "Reading array"
for ((i=0;i<size;i++))
do
	read a[$i]
done
echo "Reading key"
read key
for((i=0;i<size;i++))
do
	if ((a[$i]==$key))
	then
		echo "Search successful"
		exit 0
	fi
done
echo "Element not found."
