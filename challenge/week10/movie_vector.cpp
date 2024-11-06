#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Movie {
    string name;
    double rating;

    Movie(string n, double r) : name(n), rating(r) {}
};

int main() {
    vector<Movie> movies;
    movies.push_back(Movie("titanic", 9.9));
    movies.push_back(Movie("gone with the wind", 9.6));
    movies.push_back(Movie("terminator", 9.7));

    cout << "영화 정보:" << endl;
    for (const Movie& movie : movies) {
        cout << movie.name << ": " << movie.rating << endl;
    }

    return 0;
}
