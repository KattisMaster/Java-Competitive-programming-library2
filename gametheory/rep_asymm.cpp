/* KTH ACM Contest Template Library
 *
 * Game Theory/Rep Asymm/Rep Asymm Pseudo
 *
 * Pseudo-kod for repetitive asymmetric games which starts from the end
 * positions and calcs backward.
 *
 * Credit:
 *   By Erik Bernhardsson
 *   Based on Jimmy Mardell's text on the subject...
 *   Slightly Modified by David Rydh
 */

struct position{
  char win;	// vem som vinner, den som �r vid draget (isf 1) eller inte (isf -1)
  mer data som beh�vs f�r att beskriva br�det...
  int nMoves; 	// hur m�nga valm�jligheter man har kvar
}positions[antal_positioner];


#define QUEUELEN 0x10000

struct{
  st�llning
}queue[QUEUELEN];

int pushPtr;
int popPtr;

int pop(*st�llning){
  if(popPtr==pushPtr)
    return 0;
  *st�llningen=pop...
    popPtr=(popPtr+1)%QUEUELEN;
  return 1;
}

void push(st�llning){
  pusha st�llningen...
    pushPtr=(pushPtr+1)%QUEUELEN;
}

int generateMoves(st�llning, int *moves, int backwards){
  // en funktion som returnerar en lista med drag som g�r att g�ra
  // fr�n en given position (pos)

  if(!backwards){
    for(varje drag man kan g�ra framl�nges){
      if(moves)
	moves[nMoves]=den st�llningen som uppkommer om man g�r det draget;
      nMoves++;
    }
    return nMoves;
  }else{
    for(varje drag man kan g�ra bakl�nges){
      if(moves)
	moves[nMoves]=den st�llningen som uppkommer om man
	              g�r det draget bakl�nges;
      nMoves++;
    }
    return nMoves;
  }
}

void set((n�n typ) st�llning, char winning) {
  // en funktion som s�tter att en viss st�llning �r evaluerad till n�got

  positions[st�llning].win=winning;
  push(st�llning);
}

void test(){
  // nollst�ll k�n
  pushPtr=0;
  popPtr=0;

  // initiera listan med varje st�llning
  for(alla st�llningar som finns){               
    positions[st�llning].willWin=UNKNOWN;

    // antalet drag man kan g�ra fr�n den st�llningen
    positions[st�llning].nMoves=generateMoves(st�llning, 0, 0);
  }

  // s�tt alla positioner d�r man vinner till vunna
  for(alla st�llningar d�r man vinner){
    set(st�llning, 1);
    set(st�llning, 1);
  }
  for(alla st�llningar d�r man f�rlorar){
    set(st�llning, -1);
    set(st�llning, -1);
  }

  // g� igenom speltr�det
  st�llning moves[massa];
  while(pop(&st�llning)){
    // processa allt som ligger i k�n

    // generera alla platser bakl�nges
    nMoves=generateMoves(st�llning, moves, 1);

    if(positions[st�llning].willWin==-1){
      // is�fall kommer ju alla dragen som ledde hit vara vinnande

      for(a=0;a<nMoves;a++)
	if(positions[moves[a]].willWin==UNKNOWN)
	  set(moves[a],1);
    }else{
      // man vinner, allts� minskar valm�jligheterna f�r draget innan.
      // Om den inte har n�gra valm�jligheter kvar f�rlorar den.

      for(a=0;a<nMoves;a++)
	if( positions[moves[a]].willWin==UNKNOWN &&
	    --positions[moves[a]].nMoves==0)
	  set(moves[a],-1);
    }
  }
}
