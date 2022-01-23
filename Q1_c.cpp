#include <iostream>
#include<ctime>
#define N 101

using namespace std;

const __int128 NIL = -1;
__int128 Fib_List[N];

void init()
{
    for(__int128 i=0; i<N; i++)
        Fib_List[i] = NIL;
}

__int128 fib(int x) {
    if(Fib_List[x] == NIL) {
        if(x <= 1)
            Fib_List[x] = x;
        else
            Fib_List[x] = fib(x-1) + fib(x-2);
    }
    return Fib_List[x];
}

std::ostream&
operator<<( std::ostream& dest, __int128_t value )
{
    std::ostream::sentry s( dest );
    if ( s ) {
        __uint128_t tmp = value < 0 ? -value : value;
        char buffer[ 256 ];
        char* d = std::end( buffer );
        do
        {
            -- d;
            *d = "0123456789"[ tmp % 10 ];
            tmp /= 10;
        } while ( tmp != 0 );
        if ( value < 0 ) {
            -- d;
            *d = '-';
        }
        int len = std::end( buffer ) - d;
        if ( dest.rdbuf()->sputn( d, len ) != len ) {
            dest.setstate( std::ios_base::badbit );
        }
    }
    return dest;
}

int main()
{
    init();
    timespec start, end;
    clock_gettime(CLOCK_REALTIME, &start);
    int n=99;
    cout << "\nFibonnaci number is : " << fib(n) << endl;

    clock_gettime(CLOCK_REALTIME, &end);
    long long secs = end.tv_sec - start.tv_sec;
    long long nanosecs = end.tv_nsec - start.tv_nsec;
    long double elapsed = secs + nanosecs*(long double)1e-9;
    cout<<"\nTime taken: "<<elapsed<<" seconds\n";
}
