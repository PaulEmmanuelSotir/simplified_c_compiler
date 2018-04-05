echo "Lancement des tests back-end"

PROG='./bin/debug/c_compiler'
TEST='./tests/Demo/back/'

echo $TEST*.c

for f in $TEST*.c;
do
    $PROG $TEST $f -c
    read -p "Press enter to continue"
done
