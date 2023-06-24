echo "Reading the number to find the factorial of... "
read num
if [ $num -eq 0 ]
then
	echo "Factorial of 0 is 1"
	exit 0
fi
fact=1
n=$num
while [ $n -ne 1  ]
do
	fact=$((fact*n))
	n=$((n-1))
done
echo "Factorial of $num is $fact"
