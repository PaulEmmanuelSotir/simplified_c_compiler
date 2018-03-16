expression(X) :-
   append(A,B,X),
   terme(A),
   expression_suite(B).
expression_suite(['+'|X]) :-
   append(A,B,X),
   terme(A),
   expression_suite(B).
expression_suite([]). % expression_suite -> epsilon
terme(X) :-
   append(A,B,X),
   facteur(A), 
   terme_suite(B).
terme_suite(['*'|X]) :-
   append(A,B,X),
   facteur(A),
   terme_suite(B).
terme_suite([]). % terme_suite -> epsilon
facteur([X]) :-
   number(X).
