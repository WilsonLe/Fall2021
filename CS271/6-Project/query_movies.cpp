#include<iostream>
#include <fstream>
#include <string>
#include <sys/time.h>
#include "dict.h"
#include "data.h"
using namespace std;

int main()
{
	Dict<str, string> movieDict;
	ifstream movieData("movies_mpaa.txt");

	if(movieData.is_open()) {   
		string movie;
		// start timer
		timeval timeBefore, timeAfter;
		long diffSeconds, diffUSeconds;
		gettimeofday(&timeBefore, NULL);

		while(getline(movieData, movie)){  
			int titleEnd = movie.find("\t");
			string title = movie.substr(0, titleEnd);  
			string cast = movie.substr(titleEnd + 1, movie.size() - titleEnd - 1);
			Data<str, string>* movie = new Data<str, string>(str(title), cast);
			movieDict.insert(movie);
		}
		movieData.close();  

		// stop timer
		gettimeofday(&timeAfter, NULL);
		diffSeconds = timeAfter.tv_sec - timeBefore.tv_sec;
		diffUSeconds = timeAfter.tv_usec - timeBefore.tv_usec;
		cout << diffSeconds + diffUSeconds/1000000.0 << endl;

	}
	string title = "\"A Woman of Independent Means\" (1995)";
	Data<str, string>* sample = new Data<str, string>(str(title), "");
	Data<str, string>* movie = movieDict.get(*sample);
    cout<< *movie << endl;
}