grammar GramComp;

program: (INCLUDE | declaration | definition | function)*;

WS: [ \t\n\r]+ -> skip;

instruction: 
	'break' ';' 												# break
	| 'continue' ';'											# continue
	| structure	';'												# structure_instr
	| 'return' expression ';'									# return
	| expression ';'											# expression_instr
;

function: (type | 'void') IDENTIFIER '(' args? ')' '{' (function_init)* (instruction)* '}';

args: ('void' | type IDENTIFIER (',' type IDENTIFIER)*);

function_init:
	declaration		# functioninit_decl
	| definition	# functioninit_def;

expression:
	'(' expression ')'				# parenthesis
	| '-' expression				# unary_minus
	| '!' expression				# not
	| expression '+' expression		# plus
	| expression '-' expression		# minus
	| expression '*' expression		# mult
	| expression '/' expression		# div
	| expression '==' expression	# equal
	| expression '!=' expression	# different
	| expression '<' expression		# inf
	| expression '<=' expression	# infequal
	| expression '>' expression		# sup
	| expression '>=' expression	# supequal
	| affectation					# affect_epxr
	| array_expr					# array_constant
	| INTEGER						# integer
	| QUOTED_CHAR_LITERAL			# char_literal
	| STRING_LITERAL				# string_literal
	| IDENTIFIER '(' (expression (',' expression)*)? ')'	# fucntioncall
	| IDENTIFIER					# variable_usage
;

structure:
	'if' '(' expression ')' '{' (instruction)* '}' else_structure?	# if
	| 'while' '(' expression ')' '{' (instruction)* '}'				# while
;

else_structure: 'else' '{' (instruction)* '}' # else;

affectation:
	unary_affectation  		# unary_affect
	| binary_affectation 	# binary_affect
;

unary_affectation:
	IDENTIFIER ('[' expression ']')? '=' expression		# affect_eq
	| IDENTIFIER ('[' expression ']')? '+=' expression	# plus_equal
	| IDENTIFIER ('[' expression ']')? '-=' expression	# minus_equal
	| IDENTIFIER ('[' expression ']')? '/=' expression	# div_equal
	| IDENTIFIER ('[' expression ']')? '*=' expression	# mult_equal
	| IDENTIFIER ('[' expression ']')? '%=' expression	# modulo_equal
;

binary_affectation:
	IDENTIFIER ('[' expression ']')? '++'				# post_inc
	| IDENTIFIER ('[' expression ']')? '--'				# post_dec
	| '--' IDENTIFIER ('[' expression ']')?				# pre_dec
	| '++' IDENTIFIER ('[' expression ']')?				# pre_inc
;

definition:
	atomic_type IDENTIFIER '=' expression (',' IDENTIFIER '=' expression)* ';'     # define
	| atomic_type IDENTIFIER '[' INTEGER ']' '=' expression (',' IDENTIFIER '[' INTEGER ']' '=' expression)* ';' # deftable
;

declaration:
	atomic_type IDENTIFIER (',' IDENTIFIER)* ';' # declare
	| atomic_type IDENTIFIER '[' INTEGER ']' (',' IDENTIFIER '[' INTEGER ']')* ';' # decltable
;

array_expr: '{' ((INTEGER | QUOTED_CHAR_LITERAL) (',' (INTEGER | QUOTED_CHAR_LITERAL))*)? '}';

atomic_type: CHAR | INT32_T | INT64_T;

type: (CHAR | INT32_T | INT64_T) ('[' ']')?;

CHAR: 'char';
INTEGER: [0-9]+;
INT32_T: 'int' | 'int32_t';
INT64_T: 'long' | 'int64_t';
IDENTIFIER: [a-zA-Z_][a-zA-Z0-9_]*;
fragment CHAR_LITERAL: ~('\\'|'\n'|'\r') | '\\'.;
QUOTED_CHAR_LITERAL: '\'' CHAR_LITERAL '\'';
STRING_LITERAL: '"' (CHAR_LITERAL)* '"';
INCLUDE: '#include' ('<' (CHAR_LITERAL)+ '>' | STRING_LITERAL);