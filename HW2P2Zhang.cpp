#include <iostream>
#include <fstream> 
using namespace std;

#define debug 0
const string cc[5] = {"G","PG","PG-13","R"};

class Movie{
    private:
    string rating,name;
    int money,ratingClass;
    
    void setRatingClass(){
        for(int i = 0; i < 5; i++) 
            if(rating == cc[i]) ratingClass = i;
    }

    public:
    Movie(){
        rating = name = "";
        money = -1;
    }

    Movie(string name, string rating,int money){
        this->name = name;
        this->rating = rating;
        this->money = money;
        setRatingClass();
    }

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

    double movieShowing(int n){
        money += n * 12;
        return money;
    }
    Movie mergeMovie(Movie m){
        if(m.getName() == this->name){
            this->ratingClass = min(m.getRatingClass(),this->ratingClass);    
            rating = cc[ratingClass]; 
            this->money += m.getMoney();
        } else{
            return Movie("Could not combine","",-1);
        }
        return *this; 
    }

};

int main(){
    //empty movie
    Movie a = Movie();

    Movie b = Movie("b","PG",1);
    Movie b2 = Movie("b","PG-13",1);
    Movie c = Movie("c","R",1);

    //should return 144+1
    b.movieShowing(12); 
    cout << "MONEY FROM B " << b.getMoney() << endl;
     
    //merging fail
    Movie merged = c.mergeMovie(b);
    cout << merged.getName() << endl;

    //merge fine
    //should be b pg-13 146
    merged = b2.mergeMovie(b);
    cout << merged.getName() << " " << merged.getRating() << " " << merged.getMoney()  << endl;
}
