/*
Time limit: 1.00 s Memory limit: 512 MB
A factory has n machines which can be used to make products. Your goal is to make a total of t products.
 
For each machine, you know the number of seconds it needs to make a single product. The machines can work simultaneously, and you can freely decide their schedule.
 
What is the shortest time needed to make t products?
 
Input
 
The first input line has two integers n and t: the number of machines and products.
 
The next line has n integers k1,k2,…,kn: the time needed to make a product using each machine.
 
Output
 
Print one integer: the minimum time needed to make t products.
 
Constraints
1≤n≤2⋅10^5
1≤t≤10^9
1≤ki≤10^9
Example
 
Input:
3 7
3 2 5
 
Output:
8
 
Explanation: Machine 1 makes two products, machine 2 makes four products and machine 3 makes one product.
*/
 
#include<iostream>
#include<climits>
using namespace std;
 
long long bin_search(long long start,long long end,int& packets,int* arr,int& n){
 
    long long answer = end;
 
    while(start<=end){
        long long mid = start + (end-start)/2;
        long long temp = 0;
        bool flag = false;
        for(int i=0;i<n;i++){
            temp += mid/arr[i];
            if(temp > 1000000000000000000){ // to avoid getting out of range of long
                flag = true;
                break;
            }
        }
        //cout<<start<< " "<<mid<<" "<<end<<" "<<temp<<"***"<<endl;
        if(temp >= packets || flag ){
            answer = min(answer,mid);
            end = mid - 1;
        }
        else
            start = mid + 1;
    }
    return answer;
 
}
 
/*long long min_time_taken(int* arr,int& n,int& t){
    if(t == 0)
        return 0;
    long long candidate_time = 1;
 
    while(true){
        long long packets = 0;
        for(int i=0;i<n;i++)
            packets += candidate_time/arr[i];
        if(packets == t)
            return candidate_time;
        else if(packets > t)
            break;
        candidate_time *= 2;
    }
    //cout<<candidate_time/2<<"  "<<candidate_time<<endl;
    return bin_search(candidate_time/2,candidate_time,t,arr,n);
 
}*/
 
int main(){
    int n,t;
    //n = 10;
    //t =10;
    cin>>n>>t;
    int* time = new int[n];//{6 ,6 ,4 ,3 ,4 ,9 ,3 ,2 ,6 ,10};
   
  
    for(int i=0;i<n;i++)
        cin>>time[i];
     
    //cout<<min_time_taken(time,n,t);
    cout<<bin_search(1,1000000000000000000,t,time,n);
    return 0;
}