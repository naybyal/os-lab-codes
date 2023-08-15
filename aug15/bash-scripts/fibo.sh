echo "Reading the limit"
read num
n1=0
n2=1
while [ $num -lt 3 ]
do
	if [ $num = 0 ]
	then
		echo "0"
		exit 0
	else
		echo $n1
		echo $n2
		exit 0
	fi
done
count=2
echo $n1
echo $n2
while [ $count != $num ]
do
	n3=$((n1+n2))
	echo $n3
	n1=$n2
	n2=$n3
	count=$((count+1))
done



