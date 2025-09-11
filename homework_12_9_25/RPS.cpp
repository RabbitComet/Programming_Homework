#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>

class Player{
    
private:
    static int globalID;
    int id;
    int score;
    bool isBot;
    std::string name;
    std::string choice;
    
public:
    Player(std::string name, bool isBot){
        this->name = name;
        this->isBot = isBot;
        score = 0;
        id = globalID++;
        
    }
    
    void makeChoice(){
        if (isBot) {
            int roll = rand() % 3;
            if (roll == 0) {
                choice = "rock";
            }
            else if (roll == 1) {
                choice = "paper";
            }
            else {
                choice = "scissors";
            }
        }
        else {
            do {
                std::cout << name << ", choose rock, paper or scissors.\n";
                std::cin >> choice;
            } while (choice != "rock" && choice != "paper" && choice != "scissors");
        }

        std::cout << name << " chose " << choice << std::endl;
    }
    
    std::string getChoice(){
        return choice;
    }
    
    std::string getName(){
        return name;
    }
    void addScore(){
        score++;
    }
    int getScore(){
        return score;
    }
    
};

int Player::globalID = 0;

class Game{
    private:
        std::vector<Player> players;
        
        void play(){
            players[0].makeChoice();
            players[1].makeChoice();

            std::string choice1 = players[0].getChoice();
            std::string choice2 = players[1].getChoice();
            bool gameState = false;
                
            if(choice1 == choice2){
                std::cout<<"Draw!\n";
                return;
            }
            else if(choice1 ==  "rock"){
                if(choice2 == "scissors"){
                    gameState = true;
                }
            }
            else if(choice1 == "paper"){
                if(choice2 == "rock"){
                    gameState = true;
                }                
            }
            else if(choice1 ==  "scissors"){
                if(choice2 == "paper"){
                    gameState = true;
                }
            }
            
            
            if(gameState){
                players[0].addScore();
                std::cout<<players[0].getName()<< " takes the round!\n";
                
            }
            else{
                players[1].addScore();
                std::cout<<players[1].getName()<< " takes the round!\n";
            }
            
            showScores();
            
        }
        
        void endGame(){
            if(players[0].getScore() == 3){
                    std::cout<<players[0].getName()<< " wins!\n";
            }
            
            else{
                    std::cout<<players[1].getName()<< " wins!\n";
            }
        }
        
        void showScores(){
            std::cout<<players[0].getName() << ": " << players[0].getScore()<<std::endl;
            std::cout<<players[1].getName() << ": " << players[1].getScore()<<std::endl;
        }
    
    public:
        void addPlayer(Player player){
            players.push_back(player);
        }
        
        void startGame(){
            showScores(); 
            
            while(players[0].getScore() != 3 && players[1].getScore() != 3){
                play();
            }
            
            endGame();
        
        }
    
};

int main(){
    srand(time(0));

    bool gameType;
    
    std::cout << "type 0 for CPU game, 1 for PvP.\n";
    std::cin >> gameType;
    
    std::string name1;
    std::string name2 = "Bot";

    std::cout << "Enter name for P1.\n";
    std::cin >> name1;

    if (gameType) {
        std::cout << "Enter name for P2.\n";
        std::cin >> name2;
    }

    Player player1(name1,false);
    Player player2(name2,!gameType);
    
    Game game;
    
    game.addPlayer(player1);
    game.addPlayer(player2);
    
    game.startGame();
    
    return 0;
}