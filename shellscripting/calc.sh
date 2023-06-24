echo "Reading the operands A and B"
read a
read b
echo "1) ADD 2) SUB 3) MUL 4) DIV "
read opt
case $opt in
	1)res=$((a+b))
		;;
	2)res=$((a-b))
		;;
	3)res=$((a*b))
		;;
	4)res=$((a/b))
		;;
esac
echo "Result -> $res"
