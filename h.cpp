#include <bits/stdc++.h>
using namespace std;


void dis(vector<vector<int>> ar){
    int n=ar.size();
    int m=ar[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<ar[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<endl;
}

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<vector<int>> ar(n,vector<int>(n));
	    vector<vector<int>> left(n,vector<int>(n));
	    vector<vector<int>> rightse(n,vector<int>(n));
	    vector<vector<int>> upwardse(n,vector<int>(n));
	    vector<vector<int>> downwardse(n,vector<int>(n));
	    vector<vector<int>> res(n,vector<int>(n));
	    int ans=0;
	    
	    for(int i=0;i<n;i++){
	        string a;
	        cin>>a;
	        for(int j=0;j<n;j++){
	            ar[i][j]=a[j]-'0';
	        }
	    }
	   // dis(ar);
	   // cout<<"shagun"<<endl;
	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            if(j==0){
	                left[i][j]=ar[i][j];
	            }
	            else if(ar[i][j]==0){
	                left[i][j]=0;
	            }
	            else{
	                left[i][j] = left[i][j-1] + 1;
	            }
	        }
	    }
	   // dis(left);
	   // cout<<"sa"<<endl;
	    for(int i=0;i<n;i++){
	        for(int j=n-1;j>=0;j--){
	            if(j==n-1){
	                rightse[i][j]=ar[i][j];
	            }
	            else if(ar[i][j]==0){
	                rightse[i][j]=0;
	            }
	            else{
	                rightse[i][j] = rightse[i][j+1] + 1;
	            }
	        }
	    }
	   // dis(rightse);
	   // cout<<"rewq"<<endl;
	    
	    for(int j=0;j<n;j++){
	        for(int i=0;i<n;i++){
	            if(i==0){
	                upwardse[i][j]=ar[i][j];
	            }
	            else if(ar[i][j]==0){
	                upwardse[i][j]=0;
	            }
	            else{
	                upwardse[i][j] = upwardse[i-1][j] + 1;
	            }
	        }
	    }
	   // dis(upwardse);
	   // cout<<"ytew"<<endl;
	    for(int j=0;j<n;j++){
	        for(int i=n-1;i>=0;i--){
	            if(i==n-1){
	                downwardse[i][j]=ar[i][j];
	            }
	            else if(ar[i][j]==0){
	                downwardse[i][j]=0;
	            }
	            else{
	                downwardse[i][j] = downwardse[i+1][j] + 1;
	            }
	        }
	    }
	   // cout<<"op["<<endl;
	    
	   // dis(downwardse);
	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	           // if(i==1 && j==1){
	           //     cout<<left[i][j]<<" "<<rightse[i][j]<<" "<<upwardse[i][j]<<" "<<downwardse[i][j]<<endl;
	           // }
	            if(ar[i][j]==0){
	                res[i][j]=0;
	            }
	            else{
	                int m=min(left[i][j],upwardse[i][j]);
	                m--;
	                int temp=1;
	                for(int k=m;k>0;k--){
	                    if(rightse[i-k][j-k]>k && downwardse[i-k][j-k]>k){
	                        temp++;
	                    }
	                }
	                res[i][j]=temp;
	            }
	        }
	    }
	    for(int i=0;i<n;i++){
	        for(int j=0;j<n;j++){
	            ans+=res[i][j];
	        }
	    }
	   // dis(res);
	   cout<<ans<<endl;
	}
}