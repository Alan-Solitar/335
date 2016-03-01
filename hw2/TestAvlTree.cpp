#include <iostream>
#include "AvlTree.h"
using namespace std;

    // Test program
int main( )
{
    AvlTree<int> t;
    const int numbers = 400;
    const int gap  =   3711;
    int i;

    cout << "Height is " << t.heightOfTree() << endl;
    cout << "Checking... (no more output means success)" << endl;

    cout << "Inserting... " << endl;
    for( i = gap; i != 0; i = ( i + gap ) % numbers ) {
      cout << i << " ";
        t.insert( i );
    }
    cout << endl;
    cout << "Height is " << t.heightOfTree() << endl;

    cout << "Removing... " << endl;
    for( i = 1; i < numbers; i+= 2 ) {
      cout << i << " ";
      t.remove( i );
    }
    cout << endl;
    cout << "Height is " << t.heightOfTree() << endl;
    cout << "Print Tree: " << endl;
    t.printTree( );
    cout << endl;
    cout << "Min: " << t.findMin() << endl;
    cout << "Max: " << t.findMax() << endl;
    if( t.findMin( ) != 2 || t.findMax( ) != gap )
        cout << "FindMin or FindMax error!" << endl;

    for( i = 2; i < numbers; i+=2 )
        if( !t.contains( i ) )
            cout << "Find error1!" << endl;

    for( i = 1; i < numbers; i+=2 )
    {
        if( t.contains( i ) )
            cout << "Find error2!" << endl;
    }

    AvlTree<int> t2;
    t2 = t;

    for( i = 2; i < numbers; i+=2 )
        if( !t2.contains( i ) )
            cout << "Find error1!" << endl;

    for( i = 1; i < numbers; i+=2 )
    {
        if( t2.contains( i ) )
            cout << "Find error2!" << endl;
    }

    cout << "Finished testing" << endl;

    return 0;
}
