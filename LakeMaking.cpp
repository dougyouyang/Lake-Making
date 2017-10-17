//  Copyright © 2017 Dougy Ouyang. All rights reserved.

#include <iostream>

using namespace std;
typedef pair<int, int> pii;

int main()
{
    pii ins[20005];
    int r, c, e, n, sum=0;
    int ele[105][105], down[20005];
    int i, j, k;
    
    cin >> r >> c >> e >> n;
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            cin >> ele[i][j];
        }
    }
    for(i=0;i<n;i++){
        cin >> ins[i].first >> ins[i].second >> down[i];
    }
    
    for(i=0;i<n;i++){
        int lar=0, d;
        for(j=ins[i].first-1;j<ins[i].first+2;j++){
            for(k=ins[i].second-1;k<ins[i].second+2;k++){
                if(ele[j][k]>lar)
                    lar=ele[j][k];
            }
        }
        d=lar-down[i];
        for(j=ins[i].first-1;j<ins[i].first+2;j++){
            for(k=ins[i].second-1;k<ins[i].second+2;k++){
                if(ele[j][k]>d)
                    ele[j][k]=d;
            }
        }
    }
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            ele[i][j]=e-ele[i][j];
            if(ele[i][j]>0){
                sum+=ele[i][j];
            }
        }
    }
    
    cout << sum*72*72 << endl;
    
    return 0;
}
