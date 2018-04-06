echo "Lancement des tests front-end"

PROG='./bin/debug/c_compiler'
TEST='./tests/Moodle/front/ValidPrograms/'

echo $TEST*.c

for f in $TEST*.c;
do
    $PROG $TEST $f
    read -p "Press enter to continue"
done
