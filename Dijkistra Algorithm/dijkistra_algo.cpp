#include<iostream>
#include<unordered_map>
#include<vector>
#include<utility>
#include<climits>
using namespace std;

int find_min(vector<int>& min_distances,vector<bool>& isVisited,int& total_nodes){
    
    int index = -1;
    int value = INT_MAX;
    for(int i=1;i<=total_nodes;i++){
        if(!isVisited[i] && min_distances[i] <= value){
            value = min_distances[i];
            index = i;
        }
    }
    return index;
    
}

void dijkistra_algo(unordered_map<int,vector<pair<int,int>>>& graph,int total_nodes,int starting_node){
    
    vector<int> min_distances(total_nodes+1,INT_MAX);
    min_distances[starting_node] = 0;
    
    vector<bool> isVisited(total_nodes+1,false);
    
    
    for(int i=0;i<total_nodes-1;i++){
        
        int node_index = find_min(min_distances,isVisited,total_nodes);
        isVisited[node_index] = true;
        
        for(int j=0;j<graph[node_index].size();j++){
            if(!isVisited[graph[node_index][j].first] && min_distances[node_index]<INT_MAX && min_distances[node_index]+graph[node_index][j].second < min_distances[graph[node_index][j].first]){
                min_distances[graph[node_index][j].first] = min_distances[node_index] + graph[node_index][j].second;
                
            }
        }
        
    }
    
    for(int i=1;i<=total_nodes;i++){
        if(min_distances[i] == INT_MAX)
            cout<<"Shortest distance between starting node "<<starting_node<<" and node "<<i<<" : Not Possible !"<<endl;
        else
            cout<<"Shortest distance between starting node "<<starting_node<<" and node "<<i<<" : "<<min_distances[i]<<endl;
    }
    
}


int main(){
    
    unordered_map<int,vector<pair<int,int>>> graph;
    graph[1].push_back({2,12});
    graph[1].push_back({3,3});
    graph[1].push_back({4,9});
    graph[2].push_back({7,23});
    graph[2].push_back({6,2});
    graph[2].push_back({5,15});
    graph[3].push_back({7,10});
    graph[3].push_back({6,5});
    graph[3].push_back({1,3});
    graph[3].push_back({5,7});
    graph[4].push_back({7,41});
    graph[4].push_back({1,9});
    graph[5].push_back({7,12});
    graph[5].push_back({3,7});
    graph[5].push_back({2,15});
    graph[6].push_back({7,1});
    graph[6].push_back({2,2});
    graph[7].push_back({4,41});
    graph[7].push_back({6,1});
    
    int total_nodes = 7;
    int starting_node = 1;
    dijkistra_algo(graph,total_nodes,starting_node);
    
    return 0;
}