#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    int array[] = {1, 2, 3, 0, 3, 5, 2};
    ofstream os("integers", ios_base::out | ios_base::binary);
    os.write(reinterpret_cast<char *>(array), sizeof(array));
    os.close();
    ifstream is("integers", ios_base::in | ios_base::binary);
    ifstream file("integers", ios_base::in | ios_base::binary);
    if (file)
    {
        while (file)
        { //读到文件尾file为0
            streampos here = file.tellg();
            int v;
            file.read(reinterpret_cast<char *>(&v), sizeof(int));
            if (file && v == 0)
                cout << "Position " << here << " is 0" << endl;
        }
    }
    else
    {
        cout << "ERROR: Cannot open file 'integers'." << endl;
    }
    file.close();
    return 0;
}