echo "Reading string"
read str
len=${#str}
rev=""

#loops...
for((i=len-1;i>=0;i--))
do
	ch="${str:$i:1}"
	rev="$rev$ch"
done

#displaying the reverse...
echo $rev

if [ $rev = $str ]
then
	echo "It's a palindrome"
else
	echo "It's not a palindrome"
fi

