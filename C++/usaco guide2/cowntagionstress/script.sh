set -e
g++ 1.cpp -o 1
g++ 2.cpp -o 2
g++ gen.cpp -o gen
g++ val.cpp -o val
for((i = 1; ; ++i)); do
    ./gen $i > input_file
    ./val > check
    result=`cat check`
    if [ "$result" == "1" ];
    then
    ./1 < input_file > first
    ./2 < input_file > second
    diff -w first second || break
    fi
done
echo "WA on the following test:"
cat input_file
echo "Your answer is:"
cat first
echo "Correct answer is:"
cat second