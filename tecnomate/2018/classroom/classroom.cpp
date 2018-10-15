#include <iostream>
#include <vector>

using namespace std;

vector<int> bestSeat(vector<vector<int> > classLayout) {
 int maxNum=-1,n=classLayout.size(),m=classLayout[0].size(); 
    vector<int> ans(2,-1);
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
            if (classLayout[i][j]==-1){
                int sum=0;
                for (int p=-1;p<=1;p++)
                    for (int q=-1;q<=1;q++){  
                        int y=i+p,x=j+q;
                        if (y>=0 && y<n && x>=0 && x<m && classLayout[y][x]>0) sum+=classLayout[y][x];
                    }
                if (maxNum<sum){
                    maxNum=sum;
                    ans[0]=i,ans[1]=j;
                }
            }
    return ans;
}

int main () {
    int x, y, tcase = 1;
    
    while (cin >> x >> y) { 
       if (x==0 || y==0) return 0;
       vector<vector<int> > mat (x);
       for (int i=0; i<x; ++i) {
           mat[i] = vector<int>(y);
           for (int j=0; j<y; ++j) {
               cin >> mat[i][j];
            }
        }

        cout << "Case N:" << tcase++ << endl;
        vector<int> res = bestSeat(mat);
        cout << res[0] << " " << res[1] << endl;
        cout << endl;
    }
    return 0;
}
