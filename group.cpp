 /*
	- Apply (x, y) -> (x+y, x-y) so the distance function is now max(|x1-x2|, |y1-y2|)
	- Binary search by answer
	- Problem becomes to check if some points can be covered by 2 squares
	- One square has its left side at the minimum x and the other has its right side at the maximum x
	- Similarly, one square has its bottom side at the minimum y and the other has its top side at the maximum y
	- We test both pairs of squares with corners at opposite sides of the bounding box
 */
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#include <bits/stdc++.h>
using namespace std;
#define sqr 547
#define mid (l+r)/2
#define pb push_back
#define ppb pop_back
#define fi first
#define se second
#define lb lower_bound
#define ub upper_bound
#define ins insert
#define era erase
#define C continue
#define mem(dp,i) memset(dp,i,sizeof(dp))
#define mset multiset
#define all(x) x.begin(), x.end()
typedef long long ll;
typedef short int si;
typedef long double ld;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pi> vpi;
typedef vector<pll> vpll;
const ll inf=1e18;
const ll mod=1e9+7;
const ld pai=acos(-1);
#include "group.h"
ll n , mnx , mxx , mny , mxy ;
ll x[100009] , y[100009] , done[100009] ;
void fill(ll X1 , ll Y1 , ll X2 , ll Y2 ){
	if ( Y1 > Y2 ) swap ( Y1 , Y2 ) ;
	if ( X1 > X2 ) swap ( X1 , X2 ) ;
	for ( int i = 0 ; i < n ; i ++ ) {
		if ( X1 <= x[i] && x[i] <= X2 && Y1 <= y[i] && y[i] <= Y2 ) {
			done [i] = 1 ;	
		}
	}
}
ll check1 ( ll x ) {
	mem ( done , 0 ) ;
	fill ( mnx , mxy , mnx + x , mxy - x ) ;
	fill ( mxx , mny , mxx - x , mny + x ) ;
	for ( int i = 0 ; i < n ; i ++ ) {
		if ( ! done[i] ) return 0 ;
	}
	return 1 ;
}
ll check2 ( ll x ) {
	mem ( done , 0 ) ;
	fill ( mnx , mny , mnx + x , mny + x ) ;
	fill ( mxx , mxy , mxx - x , mxy - x ) ;
	for ( int i = 0 ; i < n ; i ++ ) {
                if ( ! done[i] ) return 0 ;
        }
        return 1 ;
}
int getMinimumDelay(int N, std::vector<int> X, std::vector<int> Y) {
	n = N ;
	mnx = mny = inf ;
	mxx = mxy =-inf ;
	for ( int i = 0 ; i < n ; i ++ ) {
		x[i] = X[i] + Y[i] ;
		y[i] = X[i] - Y[i] ;
	}
	for ( int i = 0 ; i < n ; i++ ) {
		mnx = min ( mnx , x[i] ) ;
		mny = min ( mny , y[i] ) ;
		mxx = max ( mxx , x[i] ) ;
		mxy = max ( mxy , y[i] ) ;
	}
	ll l = -1 , r = max ( mxx - mnx , mxy - mny ) ;
	while ( r - l > 1 ) {
		if ( check1(mid) || check2(mid) ) r = mid ;
		else l = mid ;
	}
	return r ;
}
