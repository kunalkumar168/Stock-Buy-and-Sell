//Kunal Kumar
//kunal_coder_1
#include <bits/stdc++.h>
#define ulli unsigned long long int
#define uli unsigned long int
#define ui unsigned int
#define ll long long
#define pii pair<int,int>
#define ppi pair<int,pii>
#define pll pair<ll,ll>
#define pb push_back
#define MOD 1000000007

using namespace std;
struct node
{
  int val;
  vector <pii> v;
  
  
}dp[100][100];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int t;
	cin>>t;
	
	while(t--)
	{
	    int n;
	    cin>>n;
	    
	    int arr[n];
	    for(int i=0;i<n;i++)
	    {
	        cin>>arr[i];
	    }
	    
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<n;j++)
	        {
	            dp[i][j].val=0;
	            dp[i][j].v.clear();
	        }
	    }
	    //memset(dp,0,sizeof(dp));
	    
	    //vector <int> v[n][n];
	    
	    for(int i=0;i<n;i++)
	    {
	       dp[i][i].val=0;
	       dp[i][i].v.push_back({i,i});
	    }
	    
	    for(int i=0;i<n;i++)
	    {
	        if(arr[i+1]-arr[i]>0)
	        {
	            dp[i][i+1].val=(arr[i+1]-arr[i]);
	            (dp[i][i+1].v).push_back({i,i+1});
	        }
	        else
	        {
	            dp[i][i+1].val=0;
	            dp[i][i+1].v.push_back({i,i});
	            dp[i][i+1].v.push_back({i+1,i+1});
	        }
	        
	    }
	    
	    for(int c=3;c<=n;c++)
	    {
	        for(int i=0;i<n-c+1;i++)
	        {
	            int j=i+c-1;
	            
	            int val=(arr[j]-arr[i]);
	            dp[i][j].val=val;
	            (dp[i][j].v).push_back({i,j});
	            for(int k=0;k<j;k++)
	            {
	                if((dp[i][j].val)<(dp[i][k].val+dp[k+1][j].val))
	                {
	                    (dp[i][j].v).clear();
	                    dp[i][j].val=dp[i][k].val+dp[k+1][j].val;
	                    
	                    if(!dp[i][k].v.empty())
	                    {for(auto z:dp[i][k].v)
	                    {
	                        (dp[i][j].v).push_back(z);
	                    }
	                    }
	                    
	                    if(!dp[k+1][j].v.empty())
	                    {
	                    for(auto z:dp[k+1][j].v)
	                    {
	                        (dp[i][j].v).push_back(z);
	                    }
	                    }
	                    
	                }
	            }
	        }
	    }
	    
	    bool flag=false;
	    for(auto z:dp[0][n-1].v)
	    {
	        if(z.first!=z.second)
	        {
	            flag=true;
	            cout<<"("<<z.first<<" "<<z.second<<") ";
	        }
	    }
	    
	    if(!flag)
	    {
	        cout<<"No Profit";
	    }
	   cout<<"\n";
	}
	return 0;
}
