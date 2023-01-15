#include <iostream>
#include <cstdint>
using namespace std;

void toplama(string& number1,string& number2){ 
    int64_t elde = 0; 
    int64_t placeholder = 0;  
    int64_t placeholder2 = 0; 
    int64_t total = 0; 
    int fark = number1.size() - number2.size();
    if (fark > 0) {
        number2.insert(0, fark, '0');
    } else if (fark < 0) {
        fark = abs(fark);
        number1.insert(0, fark, '0');
    }
    for(int i=number2.size()-1;i>=0;i--){
        placeholder = number1[i] - 48;
        placeholder2 = number2[i] - 48;
        total = elde + placeholder + placeholder2;
        elde = total / 10;
        number1[i] = (total % 10) + 48;
    }
    if (elde != 0) {
        number1.insert(0, 1, char(elde + 48));
    }
    cout<<number1; 
}

int main() {
    string sayi1 = "50000000000"; 
    string sayi2 = "20000000000"; 
    toplama(sayi1, sayi2);
    return 0;
}
