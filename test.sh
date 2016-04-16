if [ -z $1 ]
then

for f in input/*; do
	./a.out $f > output2.txt
	echo "Testing $f"
	diff -w ./output2.txt output/${f##*/}.out
done

else

echo Testing $1
./a.out input/$1.txt > output2.txt
diff -w ./output2.txt output/$1.txt.out

fi