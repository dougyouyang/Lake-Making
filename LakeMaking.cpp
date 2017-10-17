/*

This is free and unencumbered software released into the public domain.

Anyone is free to copy, modify, publish, use, compile, sell, or
distribute this software, either in source code form or as a compiled
binary, for any purpose, commercial or non-commercial, and by any
means.

In jurisdictions that recognize copyright laws, the author or authors
of this software dedicate any and all copyright interest in the
software to the public domain. We make this dedication for the benefit
of the public at large and to the detriment of our heirs and
successors. We intend this dedication to be an overt act of
relinquishment in perpetuity of all present and future rights to this
software under copyright law.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.

For more information, please refer to <http://unlicense.org/>

*/


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
