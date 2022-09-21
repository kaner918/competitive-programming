#https://onlinejudge.org/external/4/489.pdf
#489

from sys import stdin

round = int(stdin.readline())

while round != -1:

    secretWord = set(stdin.readline().strip())

    letters = stdin.readline().strip()
    lives = 7
    i = 0

    while i < len(letters) and len(secretWord) > 0 and lives > 0:

        if letters[i] not in secretWord:

            lives-=1
        
        else:

            secretWord.remove(letters[i])
        
        i+=1
    
    print(f"Round {round}")

    if lives > 0 and len(secretWord) > 0:

        print("You chickened out.")
    
    elif len(secretWord) > 0:

        print("You lose.")
    
    else:

        print("You win.")
        
    round = int(stdin.readline())





