#include <iostream>

// Integer sınırlarını aşan iki sayıyı nasıl toplarız? Tabii ki basamak basamak toplayarak.
using namespace std;

void toplama(string number1,string number2){ // Burası bizim toplama fonksiyonumuz
	
	int elde = 0; // toplama işleminde elde sayısını tutar.
	int placeholder = 0;  // birinci stringin basamak sayısı için yer tutucu
	int placeholder2 = 0; // ikinci stringin basamak sayısı için yer tutucu
	int total = 0; // placeholder ve placeholder2 nin toplamı

		for(int i=number2.size()-1;i>=0;i--){
			
			placeholder = number1[i]; // number1 değerinin ilk olarak son basamak sayısına erişiyoruz sonra ilk basamağa kadar gidiyoruz.
			placeholder2 = number2[i];            // number2 sayısının da aynı şekilde.
			placeholder -= 48; // iki değeri ascii türünden integer türüne çeviriyoruz. 48 ascii tablosunda 0 değerine denk gelir. Ascii tablosunda sayılar 48 ile 57 arasında yer alır Örneğin: 57 den 48 çıkarırsak 9 elde ederiz
			placeholder2 -= 48;
			
			if(elde>0){ // Önceki işlemden elde kaldıysa burda ekliyoruz. İlk döngüde başlangıcında elde olmaz çünkü hiçbir şeyi toplamadık.
				placeholder++;
				elde--;
			}
			if(placeholder+placeholder2>=10){  // eğer toplama işlemi 10 sayısını geçiyorsa o sayıdan 10 çıkarıp basamak yerine yazıyoruz ve 1 elde ekliyoruz.
				elde++;
				total = placeholder+placeholder2-10;
				number1[i] = total+48;
			}
			else{ // toplama 10 u geçmiyosa
				total = placeholder+placeholder2;
			    number1[i] = total+48;
	     	}
				
			if(i==0 && elde>0){  // En son yapılacak işlem örneğin 100 ile 950 yi topluyoruz ilk basamağa 1 eklemek zorundayız. ilk basamağa 1 ekledikten sonra sonuç 1050 olur
			
				number1.insert(0, "1");
				elde--;		
			} 
			
		}
		
		cout<<number1; // Sonucu yani Toplama işlemini number1 üzerinden hallettiğimiz için onu yazdırıyoruz.
}

int main() { // Main fonksiyon
	
	int fark = 0; // stringler arasındaki boyut farkını ölçmek için
	
	string sayi1 = "5000000000000000000000000000000000000000"; // integer değişkenini kullanarak toplayamayacağımız iki tane büyük sayı oluşturuyoruz.
	string sayi2 = "2000000000000000000000000000000000000000"; 

if(sayi1.length()!=sayi2.length()){ // eğer stringlerin boyutu aynı değilse fonksiyonumuz çalışmaz. O yüzden boyut olarak küçük olan stringin başına 0 ekliyoruz. Çünkü 0 toplama işlemine etki etmez.
	
	if(sayi1.length()>sayi2.length()){ // sayi1 büyükse sayı2 ye ekliyoruz
		
		fark = sayi1.length()-sayi2.length();
		sayi2.insert(0, fark, '0');
	}
	else{
		fark = sayi2.length()-sayi1.length(); // sayi2 büyükse sayı1 e ekliyoruz
		sayi1.insert(0, fark, '0');
	}
	
}
	toplama(sayi1,sayi2); // fonksiyonumuzu çağırıyoruz
	//Not: eksi sayıyı bu fonksiyonda toplayamayız. Sadece pozitif sayılar üzerinde çalışır.
	
	return 0;
}
