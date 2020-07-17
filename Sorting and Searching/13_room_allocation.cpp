/*
Time limit: 1.00 s Memory limit: 512 MB
There is a large hotel, and n customers will arrive soon. Each customer wants to have a single room.

You know each customer's arrival and departure day. Two customers can stay in the same room if the departure day of the first customer is earlier than the arrival day of the second customer.

What is the minimum number of rooms that are needed to accommodate all customers? And how can the rooms be allocated?

Input

The first input line contains an integer n: the number of customers.

Then there are n lines, each of which describes one customer. Each line has two integers a and b: the arrival and departure day.

Output

Print first an integer k: the minimum number of rooms required.

After that, print a line that contains the room number of each customer in the same order as in the input. The rooms are numbered 1,2,…,k.

Constraints
1≤n≤2⋅10^5
1≤a≤b≤10^9
Example

Input:
3
1 2
2 4
4 4

Output:
2
1 2 1
*/

#include<iostream>
#include<set>
#include<vector>
#include<iterator>
#include<algorithm>
using namespace std;

/*bool compf(pair<pair<int,int>,int>& a, pair<pair<int,int>,int>& b){
    if( a.first.first != b.first.first)
        return a.first.first < b.first.first;
    else {
        if(a.first.second != b.first.second)
            return a.first.second < b.first.second;
        return a.second < b.second;
    }

}*/

int main(){
    int n;
    cin>>n;

    vector<pair<pair<int,int>,int>> timings(n);
    for(int i=0;i<n;i++){
        cin>>timings[i].first.first>>timings[i].first.second;
        timings[i].second = i+1;
    }
    sort(timings.begin(),timings.end());//,compf);

    /*for(int i=0;i<n;i++){
        cout<<timings[i].first.first<<" "<<timings[i].first.second<<" "<<timings[i].second<<endl;
    }
    cout<<endl;*/

    multiset<int> roomFinishTimes;
    vector<int> respectiveRooms(n+1,0);
    int roomNum = 1;
    roomFinishTimes.insert(timings[0].first.second);
    respectiveRooms[timings[0].second] = roomNum;
    roomNum++;

    for(int i=1;i<n;i++){
       

        auto it = roomFinishTimes.lower_bound(timings[i].first.first);
        if(it == roomFinishTimes.begin()){
            roomFinishTimes.insert(timings[i].first.second);
            respectiveRooms[timings[i].second] = roomNum;
            roomNum ++;
        }
        else{
            it--;
            //cout<<(*it)<<"***"<<endl;
            int temp = distance(roomFinishTimes.begin(),it)+1;
            roomFinishTimes.erase(it);
            roomFinishTimes.insert(timings[i].first.second);
            respectiveRooms[timings[i].second] = temp;
        }
        
    }
    cout<<roomFinishTimes.size()<<endl;
    for(int i=1;i<=n;i++)
        cout<<respectiveRooms[i]<<" ";


    return 0;
}