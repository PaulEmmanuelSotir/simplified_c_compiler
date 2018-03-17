grammar GramComp;

programme: (include | declaration | definition | function)*;

instruction:
	'break' ';'													# break
	| 'continue' ';'											# continue
	| structure													# structure_instr
	| IDENTIFIER '(' (expression (',' expression)*)? ')' ';'	# fucntioncall
	| 'return' expression ';'									# return
	| expression ';'											# expression_instr
	| ';'														# semicolon_instr
;

include: '#include' (('<' (CHAR_LITERAL)* '>') | string_literal);

function: (type | 'void') IDENTIFIER '(' args? ')' '{' (function_init)* (instruction)* '}';

args:
	'void'										# void_arg
	| type IDENTIFIER (',' type IDENTIFIER)*	# args_list
;

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
	| quoted_char_literal			# char
	| string_literal				# string
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

IDENTIFIER: [a-zA-Z_][a-zA-Z0-9_]*;

string_literal: '"' (CHAR_LITERAL)* '"';

quoted_char_literal: '\'' CHAR_LITERAL '\'';

CHAR_LITERAL: [^\\\n\r] | '\\' .;

INTEGER: [0-9]+;

definition:
	type IDENTIFIER '=' expression ';' # define
	| atomic_type IDENTIFIER '[' INTEGER ']' '=' (array_expr | string_literal) ';' # deftable
;

declaration:
	type IDENTIFIER ';'								# declare
	| atomic_type IDENTIFIER '[' INTEGER ']' ';'	# decltable
;

array_expr: '{' const_expr (',' const_expr)* '}' | '[]';

const_expr: INTEGER | string_literal | quoted_char_literal;

atomic_type: CHAR | INT32_T | INT64_T;

CHAR: 'char';
INT32_T: 'int';
INT64_T: 'long';

type: atomic_type ('[' ']')?;

WS : [ \t\n\r]+ -> skip;
