set -e
g++ code.cpp -o code
g++ gen.cpp -o gen
g++ val.cpp -o val
g++ correct.cpp -o correct
for((i = 1; ; ++i)); do
    ./gen $i > input_file
    ./val > check
    result=`cat check`
    if [ "$result" == "1" ];
    then
    ./code < input_file > myAnswer
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