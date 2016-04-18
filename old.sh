if [ -z $1 ]
then

for f in oldExamples/*; do
	./a.out $f > output.txt
	file=${f%.txt}
	echo "Testing $file"
	diff -w output.txt oldOutput/${file##*/}.txt.out
done

else

echo Testing $1
./a.out oldExamples/$1.txt > output.txt
diff -w output.txt oldOutput/$1.txt.out

fi
