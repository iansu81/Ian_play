#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <utility>

using namespace std;

class UndergroundSystem
{

    // 用兩個unordered_map 來記錄資料,
    // 第一個用來記錄已經check in, 還沒checkout的人, 什麼時候開始搭車
    // 第二個用來記錄已經checkout的人, 所有的行程資料
    // 在checkout的時候把人從第一個unordered_map移除,然後計算資料之後放進第二個unordered_map
public:
    UndergroundSystem()
    {
    }

    void checkIn(int id, string stationName, int t)
    {
        traveler_data[id] = make_pair(stationName, t);
    }

    void checkOut(int id, string stationName, int t)
    {
        string startstation = traveler_data[id].first;
        string travel_from_to = startstation + stationName;
        double time_diff = t - traveler_data[id].second;
        // 題目沒有說一定要erase, 不erase會比較快
        traveler_data.erase(id);
        trip_data[travel_from_to].first += time_diff;
        trip_data[travel_from_to].second += 1;

    }

    double getAverageTime(string startStation, string endStation)
    {
        string travel_name = startStation + endStation;
        if (!trip_data.count(travel_name)) return 0;
        else return (trip_data[travel_name].first / trip_data[travel_name].second);

    }

private:
    // # key: "start station + end staion ", value: <total time, number of travlers before>
    unordered_map<string, pair<double, int>>  trip_data;
    // # key: traveler id, value: <start station name, time>
    unordered_map<int, pair<string, int> > traveler_data;

};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */