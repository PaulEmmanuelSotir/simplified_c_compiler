automate([X|Y],E,Y,F) :- 
   transition(E,X,F).
accepte([],F) :- 
   member(F,[4]),!.
accepte(X,E) :-
   automate(X,E,Y,F),
   accepte(Y,F).
transition(1,a,2).
transition(1,b,2).
transition(2,c,3).
transition(3,d,4).
