//  ।।जय जय जय बजरंगबली।।  

#include "bits/stdc++.h"
using namespace std;

#ifndef ONLINE_JUDGE
        #include "debug.hpp"
    #else
        #define debug(...)
#endif
 
#define int               long long
#define pb                push_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_frontint
#define all(x)            (x).begin(),(x).end()
#define rall(x)            (x).rbegin(),(x).rend()
#define uniq(v)           (v).erase(unique(all(v)),(v).end())
#define sz(x)             (int)((x).size())
#define fr                first
#define sc                second
#define pii               pair<int,int>
#define rep(i,a,b)        for(int i=a;i<b;i++)
#define per(i,a,b)        for(int i=a;i>=b;i--)
#define ppc               __builtin_popcount
#define ppcll             __builtin_popcountll

template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}

int __pow(int x, int y, int M) {int res = 1;while(y>0){if(y&1) res = (res*x)%M; y>>=1; x = (x*x)%M;}return res%M;}
int __pow(int x, int y) {int res = 1;while(y>0){if(y&1) res = (res*x); y>>=1; x = (x*x);}return res;}
int mi(int x, int M) {return __pow(x, M-2, M);}
int gcd(int a, int b) {if(b==0) return a; return gcd(b, a % b);}
int lcm(int a,int b) {return(a*(b/gcd(a,b)));}
int add(int a, int b, int M) {return (a+b) % M;}
int mul(int a, int b, int M) {return (a*b) % M;}
int sub(int a, int b, int M) {return (a-b+M) % M;}
const long long INF=1e18;
const int32_t M=1e9+7;
 
int fun(vector<vector<int>>traffic_outgoing,vector<vector<int>>distance,map<int,double>value,
 vector<vector<int>> degree)
{   
    int Totaltime=1080;
    vector<vector<int>>time(7,vector<int>(7));
    vector<vector<int>>flights(7,vector<int>(7));
    vector<vector<int>>trips={{1,3,4,6},{0,2},{1,6},{6},{5,6},{4},{0,2,4}};
    map<int,int>absolute_sum_of_flights;

    // Loop for calculating time taken and no of flights Required
    for(int i=0;i<7;i++)
    {
        for(int j=0;j<7;j++)
        {
            int d=distance[i][j];
            int t=distance[i][j];
            // dbg(distance[5]);
            if(d==0)
            {
                
                time[i][j]=0;

            }
            else
            {
                // dbg(i);
                // dbg(j);
                int speed=10+value[degree[i][j]];
                 time[i][j]=distance[i][j]/speed;

            }
           
        
            flights[i][j]=(traffic_outgoing[i][j]+199)/200;



        }
    }
    

    // loop for calulating the no of planes needed for going from one place to another
    for(int i=0;i<7;i++)
    {
        for(auto it:trips[i])
        {
            int t=Totaltime,c=0,count=0;
            int possible_round_trips_in_a_day=Totaltime/(time[i][it]+60+time[it][i]);
            int no_of_checkups=(possible_round_trips_in_a_day*2)/3;
            int total_time_involved=no_of_checkups*60+(possible_round_trips_in_a_day*2-1)*60+
            possible_round_trips_in_a_day*(time[i][it]+time[it][i]);
            int difference_in_time=total_time_involved-Totaltime;
            if(difference_in_time/(time[i][it]+60+time[it][i]))
            possible_round_trips_in_a_day-difference_in_time/(time[i][it]+60+time[it][i]);



            int number_of_round_trips_needed=min(flights[i][it],flights[it][i]);
            if(possible_round_trips_in_a_day>=number_of_round_trips_needed)
            {
                if(flights[i][it]>=flights[it][i])
                {
                    absolute_sum_of_flights[flights[it][i]]+=flights[i][it]-flights[it][i];
                    absolute_sum_of_flights[flights[i][it]]-=flights[i][it]-flights[it][i];
                }
            }

        }
    } 


    dbg(time);
    dbg(flights);

    
return 0;
}

int32_t main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
 vector<vector<int>> traffic_outgoing{{0, 2000, 0, 1000, 1200, 0, 1000},
                                         {800, 0, 1400, 0, 0, 0, 0},
                                         {0, 400, 0, 0, 0, 0, 800},
                                         {0, 0, 0, 0, 0,0, 1300},
                                         {0, 0, 0, 0, 0, 400, 1800},
                                         {0, 0, 0, 0, 300, 0, 0},
                                         {4000, 0, 200, 0, 500, 0, 0}};
    vector<vector<int>> distance{{0, 1000, 0, 900, 2000, 0, 0},
                                 {1000, 0, 1200, 0, 0, 0, 0},
                                 {0, 1200, 0, 0, 0, 0, 2600},
                                 {0, 0, 0, 0, 0, 0, 2000},
                                 {0, 0, 0, 0, 0, 400, 2600},
                                 {0, 0, 0, 0,0, 400, 2600},
                                 {0, 0, 0, 0, 400, 0, 0},
                                 {2500, 0, 2600, 0, 2600, 0, 0}};
    map<int,double> value{{0,1},{90,0},{180,-1},{270,0},{45,0.5},{30,0.25},{60,0.75},{315,0.5},{240,0.75}
    ,{225,0.5},{330,0.75},
    {135,0.5}};
    vector<vector<int>> degree {{-1, 0, -1, 270, 315, -1, 240},
                                         {180, -1, 45, -1, -1, -1, -1},
                                         {-1, 225, -1, -1, -1, -1, 270},
                                         {-1, -1, -1, -1, -1, 330},
                                         {-1, -1, -1, -1, -1, 180,0 },
                                         {-1, -1, -1, -1, 0, -1, -1},
                                         {135, -1, 90, -1,180 , -1, -1}};

     fun(traffic_outgoing,distance,value,degree);
}
