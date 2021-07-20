// 给出一个正整数N和长度L，找出一段长度大于等于L的连续非负整数，他们的和恰好为N。答案可能有多个，我我们需要找出长度最小的那个。
// 例如 N = 18 L = 2：
// 5 + 6 + 7 = 18
// 3 + 4 + 5 + 6 = 18
// 都是满足要求的，但是我们输出更短的 5 6 7

// 采用等差数列前n项和

#include <iostream>
using namespace std;
int main() {
    int N, L;
    cin>>N>>L;
    for(int i = L; i <= 100; i++) {
        if((2*N+i-i*i)%(2*i) == 0) // 判断以L最小值的等差数列第一项是否存在，不存在的话L++; 注意此时已经是按照数组长度进行排序了
        {
            int start = (2*N+i-i*i)/(2*i);    // a1
            for(int j = 0; j < i-1; j++) {
                cout<<start+j<<" "; //每一个数字输出后，都要加上" "
            }
            cout<<start+i-1;  //最后一个字符不能加" "
            return 0;
        }
    }
    cout<<"No"<<endl;
}
