set -e
g++ code.cpp -o code
g++ gen.cpp -o gen
g++ correct.cpp -o correct
g++ check.cpp -o check
g++ sanity.cpp -o sanity
for((i = 1; ; ++i)); do
    ./gen $i > input_file
    ./code < input_file > myAnswer
    ./correct < input_file > correctAnswer
    #Maybe the having the same file name confuses the program?

    ./check > checkfile
    ./sanity
    result=`cat checkfile`
    if [ "$result" == "0" ];
    then 
    break
    fi
done 
echo "WA on the following test:"
cat input_file
echo "Your answer is:"
cat myAnswer
echo "Correct answer is:"
cat correctAnswer