echo "Reading size.."
read size

echo "Reading array in sorted format"
for((i=0;i<size;i++))
do
	read a[$i]
done
echo "Reading key"
read key

low=0
high=$((size-1))

while((low<=high))
do
	mid=$(((low+high)/2))
	if((a[$mid]==$key))
	then
		echo "Element found"
		exit 0
	elif ((a[$mid]>$key))
	then 
		high=$((mid-1))
	else
		low=$((mid+1))
	fi
done
echo "Element not found"


