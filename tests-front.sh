echo "Lancement des tests back-end"

PROG='./bin/debug/c_compiler'
TEST='./tests/Demo/front'

echo $TEST*.c
echo "============================ Lexer error tests"
for f in $TEST/LexError/*.c;
do
    echo "-------- FILE --------"
    value=$(<$f)
    echo "$value"
    echo "------ END FILE ------"
    $PROG $TEST $f -a
    read -p "Press enter to continue"
done

echo "============================ Parser error"
for f in $TEST/SemanticError/*.c;
do
    echo "-------- FILE --------"
    value=$(<$f)
    echo "$value"
    echo "------ END FILE ------"
    $PROG $TEST $f -a
    read -p "Press enter to continue"
done

echo "============================ Syntax error"
for f in $TEST/SyntaxError/*.c;
do
    echo "-------- FILE --------"
    value=$(<$f)
    echo "$value"
    echo "------ END FILE ------"
    $PROG $TEST $f -a
    read -p "Press enter to continue"
done
