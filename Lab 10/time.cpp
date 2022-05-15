/*
Author: Martin Czarnecki
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab 10 A B C D E
*/

#include <iostream>

class Time {
    public:
        int h;
        int m;
};

enum Genre {ACTION, COMEDY, DRAMA, ROMANCE, THRILLER};

class Movie {
    public:
        std::string title;
        Genre genre;
        int duration;
};

class TimeSlot {
    public:
        Movie movie;
        Time startTime;
};

class TimeSlotInterval {
    public:
        Time startTime;
        Time endTime;
};

int minutesSinceMidnight(Time time){
    int minutes = 0;
    minutes += time.h * 60;
    minutes += time.m;
    return minutes;
}

int minutesUntil(Time earlier, Time later){
    return minutesSinceMidnight(later) - minutesSinceMidnight(earlier);
}

Time addMinutes(Time time0, int min){
    time0.m += min;
    for(time0.m; time0.m > 59; time0.m -= 60)
        time0.h++;
    return {time0.h, time0.m};
}

void printMovie(Movie mv){
    std::string g;
    switch(mv.genre){
        case ACTION       : g = "ACTION"; break;
        case COMEDY       : g = "COMEDY"; break;
        case DRAMA        : g = "DRAMA"; break;
        case ROMANCE      : g = "ROMANCE"; break;
        case THRILLER     : g = "THRILLER"; break;
    }
    std::cout << mv.title << " " << g << " (" << mv.duration << " min)";
}

void printTimeSlot(TimeSlot ts){
    Time endTime = addMinutes(ts.startTime, ts.movie.duration);
    printMovie(ts.movie);
    std::cout << " " << "[starts at " << ts.startTime.h << ":" << ts.startTime.m << ", ends by " << endTime.h << ":" << endTime.m << "]" << std::endl;
}

TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie){
    TimeSlot newTimeSlot;
    Time nextTimeStart = addMinutes(ts.startTime, ts.movie.duration);
    newTimeSlot.movie = nextMovie;
    newTimeSlot.startTime = nextTimeStart;
    return newTimeSlot;
}

bool timeOverlap(TimeSlot ts1, TimeSlot ts2) {
    if (minutesSinceMidnight(ts1.startTime) < minutesSinceMidnight(ts2.startTime)) {
        return minutesSinceMidnight(addMinutes(ts1.startTime, ts1.movie.duration)) > minutesSinceMidnight(ts2.startTime);
    } else if (minutesSinceMidnight(ts2.startTime) < minutesSinceMidnight(ts1.startTime)) {
        return minutesSinceMidnight(addMinutes(ts2.startTime, ts2.movie.duration)) > minutesSinceMidnight(ts1.startTime);
    }
    return true;
}


int main(){
    Movie movie1 = {"Back to the Future", COMEDY, 116};
    Movie movie2 = {"Black Panther", ACTION, 134};
    TimeSlot morning = {movie1, {9, 15}};
    TimeSlot daytime = {movie2, {13, 15}};
    TimeSlot evening = {movie2, {16, 45}};
    TimeSlot newTimeSlot = scheduleAfter(evening, movie1);

    printTimeSlot(morning);
    printTimeSlot(daytime);
    printTimeSlot(evening);
    printTimeSlot(newTimeSlot);
    
    std::cout << timeOverlap(morning, daytime);
}