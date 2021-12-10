set -e
g++ code.cpp -o code
g++ gen.cpp -o gen
g++ correct.cpp -o correct
for((i = 1; ; ++i)); do
    ./gen $i > input_file
    ./code < input_file > myAnswer
    result=`cat myAnswer`
    if [ "$result" != "-1" ];
    then
    
    ./correct < input_file > correctAnswer
    diff -w myAnswer correctAnswer || break
    fi
done
echo "WA on the following test:"
cat input_file
echo "Your answer is:"
cat myAnswer
echo "Correct answer is:"
cat correctAnswer