#include <stdio.h>
#include <ctime>
#include <iostream>
#include <cstdlib>
using namespace std;

#define N 101

const __int128 NIL = -1;
__int128 Fib_List[N];

void init()
{
    for(__int128 i=0; i<N; i++)
        Fib_List[i] = NIL;
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
    Fib_List[0] = 0;
    Fib_List[1] = 1;
    Fib_List[2] = 1;
    int i;
    int n=100;

    timespec start, end;
    clock_gettime(CLOCK_REALTIME, &start);

    cout<<0<<endl;
    cout<<1<<endl;
    for (i = 2; i < n; ++i)
    {
        Fib_List[i] = Fib_List[i-1] + Fib_List[i-2];
        cout << " " << Fib_List[i] << endl;
    }

    clock_gettime(CLOCK_REALTIME, &end);
    long long secs = end.tv_sec - start.tv_sec;
    long long nanosecs = end.tv_nsec - start.tv_nsec;
    long double elapsed = secs + nanosecs*(long double)1e-9;
    cout<<"\nTime taken: "<<elapsed<<" seconds\n";
    return 0;
}
