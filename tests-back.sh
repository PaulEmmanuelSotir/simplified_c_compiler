echo "Lancement des tests back-end"

PROG='./bin/debug/c_compiler'
TEST='./tests/Demo/back/'

echo $TEST*.c

for f in $TEST*.c;
do
    echo "-------- FILE --------"
    value=$(<$f)
    echo "$value"
    echo "------ END FILE ------"
    $PROG $TEST $f -c
    read -p "Press enter to continue"
done
