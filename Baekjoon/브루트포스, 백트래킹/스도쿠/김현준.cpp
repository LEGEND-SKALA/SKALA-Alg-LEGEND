#include<iostream>
using namespace std;
int arr[3][9][10], b[9][9], sz;
pair<int,int> p[82];
void cal(int index){
    if(index==sz)
    {
        for(int i=0;i<9;i++){for(int j=0;j<9;j++)cout<<b[i][j]<<' ';cout<< '\n';}
        exit(0);
    }
    int y=p[index].first, x=p[index].second;
    for(int i=1;i<=9;i++){
        if(!arr[0][y/3*3+x/3][i]&&!arr[1][y][i]&&!arr[2][x][i]){
            arr[0][y/3*3+x/3][i]=arr[1][y][i]=arr[2][x][i]=1;
            b[y][x]=i;
            cal(index+1);
            arr[0][y/3*3+x/3][i]=arr[1][y][i]=arr[2][x][i]=0;
            }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    for(int i=0;i<9;i++) for(int j=0;j<9;j++){
        cin >>b[i][j];
        arr[0][i/3*3+j/3][b[i][j]]=arr[1][i][b[i][j]]=arr[2][j][b[i][j]]=1;
        if(!b[i][j])p[sz++]={i,j};
    }
    
    cal(0);

    return 0;
}
