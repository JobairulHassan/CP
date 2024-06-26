#include<iostream>
#include <vector>
using namespace std;

int n, ans = -9999;
vector< vector<int>> mat;
void coinCnt(int cur_row, int cur_col,bool bombUsed, int isSafe, int coin)
{
    if(cur_row <0 ||cur_row>=n || cur_col>= 5 || cur_col<0 )
    {
        ans = max(ans, coin);
        return;
    }
    if(mat[cur_row][cur_col] == 0 || mat[cur_row][cur_col] == 1)
    {
        int tmp_coin = coin;
        if(mat[cur_row][cur_col] == 1)
        {
            tmp_coin++;
        }
        if(bombUsed)
        {
            isSafe--;
        }
        coinCnt(cur_row-1, cur_col-1, bombUsed, isSafe, tmp_coin);
        coinCnt(cur_row-1, cur_col, bombUsed, isSafe, tmp_coin);
        coinCnt(cur_row-1, cur_col+1, bombUsed, isSafe, tmp_coin);

    }
    else if(mat[cur_row][cur_col] == 2)
    {
        if(bombUsed && isSafe<=0)
        {
            ans = max(ans, coin);
            return;
        }
        else if(bombUsed && isSafe>0)
        {
            isSafe--;
            coinCnt(cur_row-1, cur_col-1, bombUsed, isSafe, coin);
            coinCnt(cur_row-1, cur_col, bombUsed, isSafe, coin);
            coinCnt(cur_row-1, cur_col+1, bombUsed, isSafe, coin);
        }
        else{
            bombUsed = true;
            isSafe = 4;
            coinCnt(cur_row-1, cur_col-1, bombUsed, isSafe, coin);
            coinCnt(cur_row-1, cur_col, bombUsed, isSafe, coin);
            coinCnt(cur_row-1, cur_col+1, bombUsed, isSafe, coin);
        }
    }
}
int main()
{
    int t, test=1;
    cin>> t;
    while(t--)
    {
        cin>>n;
        for(int i =0; i<n;i++)
        {
            vector<int> tmp;
            for(int j =0; j<5; j++)
            {
                int x;
                cin>>x;
                tmp.push_back(x);
            }
            mat.push_back(tmp);
        }
        int isSafe =0;
        coinCnt(n-1, 1, false, isSafe, 0);
        coinCnt(n-1, 2, false, isSafe, 0);
        coinCnt(n-1, 3, false, isSafe, 0);

        cout<<"#"<<test<<" "<<ans<<endl;
        ans = -9999;
        test++;
        mat.clear();
    }
    return 0;
}