% utilisation des différences de listes
% [X,S] où X et S sont des listes
% représente X-S (on ôte S de X)
expression(X) :- % simple wrapper
   expressiondl([X,[]]).
expressiondl([X,S]) :-
   terme([X,S1]),
   expression_suite([S1,S]).
expression_suite([X,S]) :-
   mot(X,'+',S1),
   terme([S1,S2]),
   expression_suite([S2,S]).
expression_suite([X,X]).
terme([X,S]) :-
   facteur([X,S1]),
   terme_suite([S1,S]).
terme_suite([X,S]) :-
   mot(X,'*',S1),
   facteur([S1,S2]),
   terme_suite([S2,S]).
terme_suite([X,X]).
mot([X|S],X,S).
facteur([[X|Y],Y]) :-
   number(X).
facteur([X,_]) :-
   number(X).
