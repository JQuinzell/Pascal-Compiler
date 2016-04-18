for f in oldExamples/*; do
	./a.out $f > output.txt
	file=${f%.txt}
	echo "Testing $file"
	diff -w output.txt oldOutput/${file##*/}.txt.out
done