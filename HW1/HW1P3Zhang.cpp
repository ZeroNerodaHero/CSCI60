#include <iostream>
#include <fstream> 
using namespace std;

#define debug 0
const string cc[5] = {"G","PG","PG-13","R"};

/*
Movie class
*/
class Movie{
    private:
    string rating,name;
    int money,ratingClass;
    
    /*
    sets the rating class in the same fashion as how 
    cc is defined. IE to make things simple instead of
    using if statements. 

    no pre and post bc user can't use this
    */
    void setRatingClass(){
        for(int i = 0; i < 5; i++) 
            if(rating == cc[i]) ratingClass = i;
    }

    public:
    /*
    empty contructor
    no pre
    post: creates movie
    */
    Movie(){
        rating = name = "";
        money = -1;
    }

    /*
    constructor 
    pre: all three variables need
    post: creates a movie
    */
    Movie(string name, string rating,int money):
        name(name),rating(rating),money(money){
        setRatingClass();
    }

    /*
    setters and getters
    pre and post self-explanitory
    */
    string getRating() {return rating;}
    void setRating(string newRate) {
        rating = newRate;
        setRatingClass();
    }
    int getRatingClass(){ return ratingClass;}
    string getName() {return name;}
    void setName(string newName) {rating = newName;}
    int getMoney() {return money;}
    void setMoney(int newMoney) {money = newMoney;}

    /* 
    updates the movie's money based on tickets
    pre: needs the total tickets
    post: returns money and sets money to new value
    */
    double movieShowing(int n){
        money += n * 12;
        return money;
    }

    /*
    merges movie. if the movies are not the same name then return 
    dummy movie. if it is then combine variables and finds the max rating class
    pre: user doesn't need to care
    post: a new merged movie
    */
    Movie mergeMovie(Movie m){
        if(m.getName() == this->name){
            this->ratingClass = max(m.getRatingClass(),this->ratingClass);    
            rating = cc[ratingClass]; 
            this->money += m.getMoney();
        } else{
            return Movie("Could not combine","",-1);
        }
        return *this; 
    }

    /* 
    print function
    no pre and post
    */
    void printStuff(){
        cout << "Name: " << name << endl;
        cout << "Rating: " << rating << endl;
        cout << "Money: " << money << endl;
        cout << endl;
    }
};

int main(){
    //empty movie
    Movie a = Movie();

    Movie b = Movie("b","PG",1);
    Movie b2 = Movie("b","R",1);
    Movie c = Movie("c","R",1);

    //should return 144+1
    cout << b.movieShowing(12) << endl; 
    b.printStuff();
     
    //merging fail
    Movie merged = c.mergeMovie(b);
    merged.printStuff();


    //merge fine
    //should be b G 146
    merged = b2.mergeMovie(b);
    merged.printStuff();

    cout << b.getMoney() << "+" << b2.getMoney() << endl;
    //merge fine
    //should be b G something 
    merged = b.mergeMovie(b2);
    merged.printStuff();
}
