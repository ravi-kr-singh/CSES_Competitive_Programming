#include<iostream>
#include<unordered_map>
#include<vector>
#include<utility>
#include<climits>
using namespace std;

void floyd_warshall_algo(unordered_map<int,vector<pair<int,int>>>& graph,int total_nodes){
    
    vector<vector<int>> min_dist_matrix(total_nodes+1,vector<int>(total_nodes+1,INT_MAX));
    for(int i=1;i<=total_nodes;i++)
        min_dist_matrix[i][i] = 0;
    
    for(int i=1;i<= total_nodes;i++){
        for(int j=0;j<graph[i].size();j++){
            min_dist_matrix[i][graph[i][j].first] = graph[i][j].second;
        }
    }
    
    for(int k=1;k<=total_nodes;k++){
        for(int i=1;i<=total_nodes;i++){
            for(int j=1;j<=total_nodes;j++){
                if(min_dist_matrix[i][k] != INT_MAX && min_dist_matrix[k][j] != INT_MAX)
                    min_dist_matrix[i][j] = min(min_dist_matrix[i][j],min_dist_matrix[i][k]+min_dist_matrix[k][j]);
            }
        }
    }
    
    for(int i=1;i<=total_nodes;i++){
        for(int j=1;j<=total_nodes;j++){
            if(min_dist_matrix[i][j] == INT_MAX){
                cout<<"No possible path from node "<<i<<" to node "<<j<<" !"<<endl;
            }
            else
                cout<<"Min distance between node "<<i<<" to node "<<j<<" : "<<min_dist_matrix[i][j]<<endl;
        }
    }
    
    
}


int main(){
    
    unordered_map<int,vector<pair<int,int>>> graph;
    graph[1].push_back({2,12});
    graph[1].push_back({3,3});
    graph[1].push_back({4,9});
    //graph[2].push_back({7,23});
    graph[2].push_back({6,2});
    graph[2].push_back({5,15});
    //graph[3].push_back({7,10});
    graph[3].push_back({6,5});
    graph[3].push_back({1,3});
    graph[3].push_back({5,7});
    //graph[4].push_back({7,41});
    graph[4].push_back({1,9});
    //graph[5].push_back({7,12});
    graph[5].push_back({3,7});
    graph[5].push_back({2,15});
    //graph[6].push_back({7,1});
    graph[6].push_back({2,2});
    graph[7].push_back({4,41});
    graph[7].push_back({6,1});
    
    int total_nodes = 7;

    
    floyd_warshall_algo(graph,total_nodes);
    
    return 0;
}#include<iostream>
#include<unordered_map>
#include<vector>
#include<utility>
#include<climits>
using namespace std;

void floyd_warshall_algo(unordered_map<int,vector<pair<int,int>>>& graph,int total_nodes){
    
    vector<vector<int>> min_dist_matrix(total_nodes+1,vector<int>(total_nodes+1,INT_MAX));
    for(int i=1;i<=total_nodes;i++)
        min_dist_matrix[i][i] = 0;
    
    for(int i=1;i<= total_nodes;i++){
        for(int j=0;j<graph[i].size();j++){
            min_dist_matrix[i][graph[i][j].first] = graph[i][j].second;
        }
    }
    
    for(int k=1;k<=total_nodes;k++){
        for(int i=1;i<=total_nodes;i++){
            for(int j=1;j<=total_nodes;j++){
                if(min_dist_matrix[i][k] != INT_MAX && min_dist_matrix[k][j] != INT_MAX)
                    min_dist_matrix[i][j] = min(min_dist_matrix[i][j],min_dist_matrix[i][k]+min_dist_matrix[k][j]);
            }
        }
    }
    
    for(int i=1;i<=total_nodes;i++){
        for(int j=1;j<=total_nodes;j++){
            if(min_dist_matrix[i][j] == INT_MAX){
                cout<<"No possible path from node "<<i<<" to node "<<j<<" !"<<endl;
            }
            else
                cout<<"Min distance between node "<<i<<" to node "<<j<<" : "<<min_dist_matrix[i][j]<<endl;
        }
    }
    
    
}


int main(){
    
    unordered_map<int,vector<pair<int,int>>> graph;
    graph[1].push_back({2,12});
    graph[1].push_back({3,3});
    graph[1].push_back({4,9});
    //graph[2].push_back({7,23});
    graph[2].push_back({6,2});
    graph[2].push_back({5,15});
    //graph[3].push_back({7,10});
    graph[3].push_back({6,5});
    graph[3].push_back({1,3});
    graph[3].push_back({5,7});
    //graph[4].push_back({7,41});
    graph[4].push_back({1,9});
    //graph[5].push_back({7,12});
    graph[5].push_back({3,7});
    graph[5].push_back({2,15});
    //graph[6].push_back({7,1});
    graph[6].push_back({2,2});
    graph[7].push_back({4,41});
    graph[7].push_back({6,1});
    
    int total_nodes = 7;

    
    floyd_warshall_algo(graph,total_nodes);
    
    return 0;
}