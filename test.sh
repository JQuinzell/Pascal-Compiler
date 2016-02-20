# put input/output files in a folder called input and output respectively
# name your parser "parser"
# profit 
for f in input/*; do
	./parser < $f > output.txt
	echo "Testing $f"
	diff -w output.txt output/${f##*/}.out
done