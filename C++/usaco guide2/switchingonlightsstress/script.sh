set -e
g++ code.cpp -o code
g++ gen.cpp -o gen
javac correct.java
for((i = 1; ; ++i)); do
    ./gen $i > input_file
    ./code < input_file > myAnswer
    java correct
    diff -w myAnswer correctAnswer || break
done 
echo "WA on the following test:"
cat input_file
echo "Your answer is:"
cat myAnswer
echo "Correct answer is:"
cat correctAnswer