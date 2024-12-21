#Description to the programs in this repository

###Program 1
spr.c is computerised version of the traditional game of stone paper scissors played in person with friends. But here you play against the computer. The user response is taken through the terminal once the program.

General Rules of playing are:
<ol>
<li>The user input his choice of either stone(s), paper(p) or scissor(r) in the form of characters provided alongside their names.</li>
<li>Internally the computer generated its response and comparison between the responses is made.Winner is chosen as:</li>
<ul><li>Paper wraps over Stone therefore Paper wins over Stones</li>
<li>Scissor cuts through Paper so, Scissor wins over paper</li>
<li>Stone can break through Scissors therefore, Stone wins over Scissors</li>
</ul>
<li>Upon comparison the result of comparison is printed</li>
</ol>

<b>Note</b> that any other input rather than s, p and r will result in the termination of the program

###Program 2
word_guess.c is a program to play the game of word guessing.

How to play
<ol>
<li>Here a word with missing letters is provided (example:e_e___nt given for the word elephant)</li>
<li>The user has to guess the word letter by letter by inputting the letter that he thinks occurs in the word on the terminal(hint is give for help).</li>
<li>Max 2 unsuccessful trials are allowed. More unsuccessful trials will lead to the termination of the program</li>
<li>If the user's guess occurs in the work it would be displayed as filled letter in the missing spaces</li>
</ol>

###Program 3
snakeNladder.c is the traditional game of Snakes and Ladders in the computerised form.Playing Instructions:
<ol>
<li> Maximum of 4 players can play the game</li>
<li> The number of players is provided to the program along side the command line call to the program</li>
<li>Players can choose to play with the symbols they desire to play with(example you may choose to play with '+' as your moving piece)</li>
<li>Snakes and ladders are distributed over the board which are not visible but influence the progress of the players. Landing on a snake's head would bring you down on the board and langing on a ladder's tail would upgrade your position</li>
<li>The dice rolls turn by turn for each player to determine the number of boxes to move at once</li>
</ol>