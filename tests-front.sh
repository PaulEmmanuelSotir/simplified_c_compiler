echo "Lancement des tests back-end"

PROG='./bin/debug/c_compiler'
TEST='./tests/Demo/front'

echo $TEST*.c
echo "===== Lexer error"
for f in $TEST/LexError/*.c;
do
    $PROG $TEST $f -a
    read -p "Press enter to continue"
done

echo "===== Parser error"
for f in $TEST/SemanticError/*.c;
do
    $PROG $TEST $f -a
    read -p "Press enter to continue"
done

echo "===== Syntax error"
for f in $TEST/SyntaxError/*.c;
do
    $PROG $TEST $f -a
    read -p "Press enter to continue"
done
