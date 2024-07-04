#include<iostream>
//initialisation of library
#include "Bigint class.h"
using namespace std;
int main() 
{
      BigInteger n1;                                             //n1 defined with value 0
    BigInteger n2(123);                                        //n2 defined with value int value
    BigInteger n3((long long int)1234567898765432);            //n3 defined with value long long int value
    BigInteger n4("7832467326423873423435");                   //n4 defined with string value
    BigInteger n5(n3);                                         //n5 defined with values of n3

    /********Converting to BigNumbers*********/
    int num1 = -321;
    long long int num2 = -9876543219876543;
    string str1 = "-2112321321321312421534365777";
    BigInteger n6 = to_Big(num1);                              //converting int to BigInteger
    BigInteger n7 = to_Big(num2);                              //converting long long int to BigInteger
    BigInteger n8 = to_Big(str1);                              //converting string to BigInteger

    /********user Input*********/
    BigInteger n9;
    cout<<"Enter the value for n9: ";
    cin>>n9;                                                     //Taking input from user

    cout<<"n1: "<<n1<<endl;                                      /**           Printing Values        **/
    cout<<"n2: "<<n2<<endl;                                      /**           Printing Values        **/
    cout<<"n3: "<<n3<<endl;                                      /**           Printing Values        **/
    cout<<"n4: "<<n4<<endl;                                      /**           Printing Values        **/
    cout<<"n5: "<<n5<<endl;                                      /**           Printing Values        **/
    cout<<"n6: "<<n6<<endl;                                      /**           Printing Values        **/
    cout<<"n7: "<<n7<<endl;                                      /**           Printing Values        **/
    cout<<"n8: "<<n8<<endl;                                      /**           Printing Values        **/

    
}
