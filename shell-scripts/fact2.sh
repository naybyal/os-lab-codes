echo "Read num"
read num
echo "Computing factorial..."

if((num==0))
then
	echo "Factorial of 0 is 1"
	exit 0
fi


temp=$num
fact=1
while((temp!=0))
do
	fact=$((fact*temp))
	temp=$((temp-1))
done

echo "Factorial of $num is $fact"
