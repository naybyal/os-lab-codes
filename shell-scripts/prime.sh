echo "Reading number to check if it's prime or not..."
read num
if ((num<2))
then	
	echo "Not prime."
	exit 0
fi

#checking for factors...

for((i=2;i<num;i++))
do
	if ((num%i==0))
	then 
		echo "Not prime."
		exit 0
	fi
done
echo "Prime."

