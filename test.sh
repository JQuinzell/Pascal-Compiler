if [ -z $1 ]
then

for f in input/*; do
	./a.out $f > oalOutput.oal
	file=${f%.txt}
	echo Testing ${file##*/}
	diff -w oalOutput.oal oalExamples/${file##*/}.oal
	# oal oalOutput.oal > output.txt
	# diff -w output.txt output/${f##*/}.txt.out
done

else

echo Testing $1
./a.out input/$1.txt > oalOutput.oal
diff -w oalOutput.oal oalExamples/$1.oal
# oal oalOutput.oal > output.txt
# diff -w output.txt output/$1.txt.out

fi