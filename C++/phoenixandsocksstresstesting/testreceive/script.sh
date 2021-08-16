set -e
g++ code.cpp -o code
./code > MYVAR
val=`cat MYVAR`
if [ "$val" == "0" ];
then
echo "received"
fi