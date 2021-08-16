set -e
g++ code.cpp -o code
g++ gen.cpp -o gen
g++ brute.cpp -o brute
for ((i=1;;++i)); do
    ./gen $i > input_file
    ./code < input_file > myAnswer
    ./brute < input_file > correctAnswer
    #I will write a checker script which will output a boolean value into a file. 
    #Then I will read the result from the file and check whether to break or not. 
    ./check > verdict_file
    verdict=`cat verdict_file`
    if [ "$verdict" == "0" ];
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