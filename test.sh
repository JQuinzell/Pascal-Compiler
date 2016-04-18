if [ -z $1 ]
then

for f in input/*; do
	# ./a.out $f > oalOutput.oal
	echo "Testing $f"
	file=${f%.txt}
	echo $file
	# oal oalOutput.oal > output.txt
	echo ${file##*/}
	# diff -w output.txt output/${f##*/}.txt.out
done

else

echo Testing $1
./a.out input/$1.txt > oalOutput.oal
oal oalOutput.oal > output.txt
diff -w output.txt output/$1.txt.out

fi