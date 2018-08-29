#include <iostream>
#include <string>
using namespace std;

template <class a_type> class circularArray 
{
    a_type a[10];
    
    public:
    void read_array(); //read elements into an array 
    void rotate_clock(int start); //rotate the circular array clockwise
    void rotate_anti(int start); // rotate the circular array anti-clockwise
};

template <class a_type> void circularArray<a_type>::read_array()
{
    cout << "Enter 10 elements";
    cout << endl;
        
    for (int i = 0; i < 10; i++)
    {
        cin >> a[i];
    }
}

template <class a_type> void circularArray<a_type>::rotate_clock(int start)
{
    for (int i = start; i < 10 + start; i++)
        {
            cout << a[(i % 10)] <<" ";
        }
    cout << endl;
}

template <class a_type> void circularArray<a_type>::rotate_anti(int start)
{
    for (int i = 10 + start; i > start; i--)
        {            
            cout << a[(i % 10)] <<" ";
        }
    cout << endl;
}

int main()
{   
    int n1;
    int n2;
    int n3;
    
	// to implement integer array
    circularArray<int> a1;
    
    cout<< "For Numbers:" << endl;
    a1.read_array();
    cout << "Enter the index to rotate (0 to 9)" << endl;
    cin >> n1;
    
    cout << "Clockwise from " << n1 << "th index in the array:" << endl;
    a1.rotate_clock(n1);
    cout << "Anti-clockwise from " << n1 << "th index in the array:" << endl;
    a1.rotate_anti(n1);
    
	// to implement char array
    circularArray<char> a2;
    
    cout<< "For Chars:" << endl;
    a2.read_array();
    cout << "Enter the index to rotate (0 to 9)" << endl;
    cin >> n2;
    
    cout << "Clockwise from " << n2 << "th index in the array:" << endl;
    a2.rotate_clock(n2);
    cout << "Anti-clockwise from " << n2 << "th index in the array:" << endl;
    a2.rotate_anti(n2);
    
	// to implement float array
    circularArray<float> a3;
    
    cout<< "For Float values:" << endl;
    a3.read_array();
    cout << "Enter the index to rotate (0 to 9)" << endl;
    cin >> n3;
    
    cout << "Clockwise from " << n3 << "th index in the array:" << endl;
    a3.rotate_clock(n3);
    cout << "Anti-clockwise from " << n3 << "th index in the array:" << endl;
    a3.rotate_anti(n3);
 
}
