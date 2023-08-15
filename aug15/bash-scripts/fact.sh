echo "Reading number to find factorial of..."
read num

fact=1

while [ $num -ne 1 ]
do
	fact=$((fact*num))
	num=$((num-1))
done

echo "The factorial is $fact"
