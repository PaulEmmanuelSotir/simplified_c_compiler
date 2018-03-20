grammar GramComp;

program: (INCLUDE | declaration | definition | function)*;

WS: [ \t\n\r]+ -> skip;

instruction:
	'break' ';'													# break
	| 'continue' ';'											# continue
	| structure													# structure_instr
	| IDENTIFIER '(' (expression (',' expression)*)? ')' ';'	# fucntioncall
	| 'return' expression ';'									# return
	| expression ';'											# expression_instr
	| ';'														# semicolon_instr
;

function: (type | 'void') IDENTIFIER '(' args? ')' '{' (function_init)* (instruction)* '}';

args: ('void' | type IDENTIFIER (',' type IDENTIFIER)*);

function_init:
	declaration		# functioninit_decl
	| definition	# functioninit_def;

expression:
	'(' expression ')'				# parenthesis
	| expression '+' expression		# plus
	| expression '-' expression		# minus
	| '-' expression				# minus1
	| '!' expression				# not
	| expression '*' expression		# mult
	| expression '/' expression		# div
	| expression '==' expression	# equal
	| expression '!=' expression	# different
	| expression '<' expression		# inf
	| expression '<=' expression	# infequal
	| expression '>' expression		# sup
	| expression '>=' expression	# supequal
	| affectation					# affect_epxr
	| INTEGER						# integer
	| QUOTED_CHAR_LITERAL			# char
	| STRING_LITERAL				# string
	| IDENTIFIER					# identifier
;

structure:
	'if' '(' expression ')' '{' (instruction)* '}' else_structure?	# if
	| 'while' '(' expression ')' '{' (instruction)* '}'				# while
;

else_structure: 'else' '{' (instruction)* '}' # else;

affectation:
	IDENTIFIER '=' expression						# affect_expr
	| IDENTIFIER '+=' expression					# incrementation
	| IDENTIFIER '-=' expression					# decrementation
	| IDENTIFIER '/=' expression					# dividementation
	| IDENTIFIER '*=' expression					# multmentation
	| IDENTIFIER '%=' expression					# pourcentmentation
	| IDENTIFIER ('++' | '--')						# incunairepost
	| ( '++' | '--') IDENTIFIER						# incunairepre
	| IDENTIFIER '[' expression ']' '=' expression	# table
;

definition:
	type IDENTIFIER '=' expression (',' IDENTIFIER '=' expression)* ';'            # define
	| atomic_type IDENTIFIER '[' INTEGER ']' '=' (array_expr | STRING_LITERAL) ';' # deftable
;

declaration:
	type IDENTIFIER (',' IDENTIFIER)* ';'        # declare
	| atomic_type IDENTIFIER '[' INTEGER ']' ';' # decltable
;

array_expr: '{' (const_expr (',' const_expr)*)? '}';

const_expr: INTEGER | STRING_LITERAL | QUOTED_CHAR_LITERAL;

atomic_type: CHAR | INT32_T | INT64_T;

type: atomic_type ('[' ']')?;

CHAR: 'char';
INTEGER: [0-9]+;
INT32_T: 'int' | 'int32_t';
INT64_T: 'long' | 'int64_t';
IDENTIFIER: [a-zA-Z_][a-zA-Z0-9_]*;
fragment CHAR_LITERAL: ~('\\'|'\n'|'\r') | '\\'.;
QUOTED_CHAR_LITERAL: '\'' CHAR_LITERAL '\'';
STRING_LITERAL: '"' (CHAR_LITERAL)* '"';
INCLUDE: '#include' ('<' (CHAR_LITERAL)+ '>' | STRING_LITERAL);